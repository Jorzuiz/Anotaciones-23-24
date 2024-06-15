#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define CAPACITY 5 //Aforo
#define VIPSTR(vip) ((vip) ? "  vip  " : "not vip")

/*
Control de acceso a una discoteca con un aforo limitado y prioridad en clientes.

Reglas:
	- Si el aforo esta completo, los nuevos clientes deben esperar
	- Si hay esperando vip y no vip, tienen prioridad los vip. Los no vip deben esperar a que entren los vip primero
	- Los clientes entran en orden estricto de llegada segun sean vips o no mientras el aforo no este completo
*/

/*
Se debe usar: 

- Mutex: MUTually EXclusive. El mutex da permiso para "hablar" a aquel hilo que lo tenga. Así, solo puede
realizar funciones un solo hilo mientras el resto espera o solicita el mutex. Hasta que el planificador no pase el 
mutex al siguiente hilo, este no puede hacer nada más que lo descrito anteriormente. Los mutex se usan para 
bloquear el acceso a una seccion critica de código, que es aquella en la que se modifica una variable global.

- Variables de condicion: Variable que permite el bloqueo y desbloqueo de hilos en funcion del cumplimiento o no de 
una variable. Se debe cumplir en el código que wait siempre este en un bucle while, wait siempre tiene el mutex cogido
y signal mejor con el mutex cogido. 
	- Signal permite desbloquear al menos a un hilo bloqueado por la variable de condicion
	- Broadcast permite desbloquearlos a todos los hilos bloqueados por la variable de condicion
*/

//Se hara una cola de vips y otra de no vips
struct cola{
	int new; //Siguiente persona que llegue a la cola
	int actual; //Persona siendo atendida

};

struct cliente{
	int id; //Orden de creacion del hilo
	int isvip;
};

//Vaiables globales
struct cola vips = {0,0};
struct cola no_vips = {0,0};
int occupation = 0; //Clientes dentro de la discoteca
pthread_mutex_t m; //Se necesita un mutex
pthread_cond_t emptier; //Variable de condicion

void enter_normal_client(int id)
{
	pthread_mutex_lock(&m);
	int order = no_vips.new;
	++no_vips.new; //Se avanza al siguiente de la cola 

	printf("The client %2d NO VIP arrives at queue in position %d\n", id, order);

	//Se queda esperando mientras no haya hueco, no sea su turno o no hayan entrado todos los vips (actual = new)
	while(occupation>=CAPACITY || order != no_vips.actual || vips.actual != vips.new){
		printf("The client %2d NO VIP is WAITING\n", id);
		pthread_cond_wait(&emptier, &m);
	}

	printf("The client %d NO VIP ENTERS the disco.\n", id);

	++no_vips.actual;
	++occupation;
	printf("Actual occupation: %d\n", occupation);

	pthread_mutex_unlock(&m);
}

void enter_vip_client(int id)
{
	pthread_mutex_lock(&m);
	int order = vips.new;
	++vips.new;
	printf("The client %2d VIP arrives at queue in position %d\n", id, order);

	while(occupation >= CAPACITY || order != vips.actual){
		printf("The client %2d is WAITING.\n", id);
		pthread_cond_wait(&emptier, &m); //Se espera a que se libere un hueco
	}

	//Cuando sale del wait entra a la discoteca
	printf("The client %2d VIP ENTERS the disco.\n", id);

	++occupation;
	printf("Actual occupation: %d\n", occupation);
	++vips.actual; //Se avanza el turno

	pthread_mutex_unlock(&m);
}

void dance(int id, int isvip)
{
	printf("Client %2d (%s) dancing in disco\n", id, VIPSTR(isvip));
	sleep((rand() % 3) + 1);
}

void disco_exit(int id, int isvip)
{
	pthread_mutex_lock(&m);
	
	printf("Client %2d (%s) leaves disco.\n", id, VIPSTR(isvip));
	if(occupation >0) --occupation;

	//Despierta a todos los hilos diciendo que se ha quedado un hueco libre
	//Como se esta haciendo el while wait en el resto, no hay que preocuparse de que entre un cliente no vip
	// habiendo clientes vip esperando. Entrará al que le toque y el resto volveran a dormir (seguir esperando)
	pthread_cond_broadcast(&emptier);

	pthread_mutex_unlock(&m);
}

void *client(void *arg)
{
	int num = ((struct cliente*)arg)->id;
	int _vip = ((struct cliente*)arg)->isvip;
	
	if(_vip){
		enter_vip_client(num);
	}
	else{
		enter_normal_client(num);
	}
	dance(num, _vip);
	disco_exit(num, _vip);
	
	pthread_exit(0); //termina el hilo
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE* file=NULL;

	if((file=fopen(argv[1], "r"))==NULL){
		printf("File %s could not be opened.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	int numClients=0;
	//Se parse el numero de clientes de string a int y se guarda en numClients
	fscanf(file, "%d", &numClients);

	//Se crea un array de hilos para guardar sus ids
	pthread_t* thread_ids = (pthread_t*)malloc(numClients*sizeof(pthread_t)) ;

	//Se setea todo a cero
	//memset(&thread_ids, 0, numClients*sizeof(pthread_t));

	//Informacion de cada cliente
	struct cliente* clients = (struct cliente*)malloc(sizeof(struct cliente)*numClients);

	//Inicializar mutex y variable de condicion
	pthread_mutex_init(&m, NULL);
	pthread_cond_init(&emptier, NULL);

	int clientType; //vip o no vip
	for(int i = 0; i < numClients; i++){
		//Se lee el cliente y si es 0 --> vip y si 1 --> no vip
		fscanf(file, "%d", &clientType);

		clients[i].id = i;
		clients[i].isvip = clientType;

		//Se crea el hilo con dicho cliente
		//A partir de aqui se hacen llamadas a las demas funciones desde client()
		pthread_create(&thread_ids[i], NULL, client, &clients[i]);
	}

	//Se borran los hilos
	for(int i = 0; i<numClients; i++){
		pthread_join(thread_ids[i], NULL);
	}

	pthread_mutex_destroy(&m);
	pthread_cond_destroy(&emptier);

	free(clients);
	free(thread_ids);
	fclose(file);
	return 0;
}
