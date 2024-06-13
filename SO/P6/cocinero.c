#define _XOPEN_SOURCE 500 //Para sigaction

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/mman.h> //Para memoria compartida
#include <signal.h> //Para el uso de señales
#include <semaphore.h> //Para el uso de semaforos
#include <fcntl.h> //Para el uso de O_ flags

#define M 10

//Se usaran semaforos y objetos de memoria compartida
//Se trata de un problema de productor-consumidor con distintos procesos en lugar de con distintos hilos de un 
// proceso

/*
Reglas y restricciones:
	- Cada salvaje se sirve una racion de un caldero
	- Si este esta vacio avisan al cocinero para que reponga
	- Los salvajes no pueden invocar a la funcion getServingsFromPot() si esta vacio
	- El cocinero solo puede invocar putServingsInPot() si esta vacio
*/

/*
COCINERO:
Solo hay un proceso de este programa y este mismo crea los recursos compartidos y ejecuta la funcion cocinero().
Este programa tendra un manejador de señales para SIGINT y SIGTERM. Cuando sean capturadas el programa debe terminar,
eliminando todos los recursos compartidos.
*/

/*
	- Semaforos: objeto que restringe el acceso a una region de datos compartida. 
	- Memoria compartida: datos que se comparten entre varios procesos y que pueden tener permisos de escritura/lectura
*/

/*
Productor
	- Crea los semaforos con nombre (sem open)
	- Crea un archivo (open)
	- Le asigna espacio (ftruncate)
	- Proyecta el archivo en su espacio de direcciones (mmap)
	- Utiliza la zona de memoria compartida
	- Desproyecta la zona de memoria compartida (munmap)
	- Cierra y borra el archivo

Consumidor
	- Abre los semaforos (sem open)
	- Debe esperar a que el archivo este creado para abrirlo (open)
	- Proyecta el archivo en su espacio de direcciones (mmap)
	- Utiliza la zona de memoria compartida
	- Cierra el archivo
*/

//VARIABLES GLOBALES
int finish = 0; //1--> true, 0 --> false
//Semaforo para caldero con y sin comida. No es con semaforos a modo de cerrojo
// porque los salvajes acceden al caldero de uno en uno
sem_t* full;
sem_t* empty;
int* caldero; //Importante que sea un puntero porque formara parte de la region de memoria compartida

//En caso de cierre abrupto el handler se encarga de cerrar y borrar los datos compartidos
void signalHandler(int signum){

	sem_post(empty);
	finish = 1;
	//Se elimina el nombre del objeto en memoria compartida
	shm_unlink("/CALDERO");
	//Se desproyecta la memoria compartida
	munmap(caldero, sizeof(int));
	//Se eliminan del sistema
	sem_unlink("/FULL");
	sem_unlink("/CLOSE");
	//Se cierran los semaforos
	sem_close(full);
	sem_close(empty);
}

void putServingsInPot(int servings)
{
	(*caldero) = servings;
	printf("Filling pot %d\n", (*caldero));
}

void cook(void)
{
	while(!finish) {
		sem_wait(empty); //el resto esperaa que se llene
		putServingsInPot(M);
		sem_post(full); //avisa de que ya se ha llenado
	}
}

int main(int argc, char *argv[])
{
	//Declaracion de las acciones asociadas a las señales
	struct sigaction actionSignals;
	actionSignals.sa_handler = signalHandler;
	sigemptyset(&actionSignals.sa_mask);
	actionSignals.sa_flags = SA_RESTART;

	if(sigaction(SIGINT, &actionSignals, NULL)==-1){
		perror("sigaction SIGINT\n");
		exit(EXIT_FAILURE);
	}

	if(sigaction(SIGTERM, &actionSignals, NULL)==-1){
		perror("sigaction SIGTERM\n");
		exit(EXIT_FAILURE);
	}

	//A PARTIR DE AQUI SE CREA LA MEMORIA COMPARTIDA
	//Este es el objeto que se va a proyectar en la region de memoria compartida
	int shared;
	//Las flags y los modos son iguales a cuando se hace open de un fichero
	//Se ha abierto de manera que se puede escribir y leer; y escritura y lectura, 
	// escritura y ejecucion para usuario y grupo
	shared = shm_open("/CALDERO", O_RDWR|O_CREAT, S_IRWXU | S_IRWXG); //Se obtiene el descriptor
	//El fichero referenciado por shared se trunca al tamaño indicado como segundo parametro
	ftruncate(shared, sizeof(int));

	//Ahora, se proyecta el objeto en memoria usando MAP_SHARED
	//(address de memoria, tamaño, flags de proteccion, flags de visibilidad, descriptor de mem compartida, offset)
	//Si address de memoria esta a NULL, el kernel decide el sitio donde ponerlo, es la mejor opcion
	caldero = (int*)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, shared, 0);

	//Se crean los semaforos con nombre
	full = sem_open("/FULL", O_CREAT, S_IRUSR | S_IWUSR, 0);
	if(full == SEM_FAILED){
		perror("sem open FULL failed\n");
		exit(EXIT_FAILURE);
	}
	empty=sem_open("/EMPTY", O_CREAT, S_IRUSR | S_IWUSR, 1);

	//Se puede obtener el valor del semaforo empty usando sem_getvalue(empty, &variable) para debug

	//A partir de aqui se ejecuta hasta que finish valga true
	cook();

	printf("End of program\n");

	//Se elimina el nombre del objeto en memoria compartida
	shm_unlink("/CALDERO");
	//Se desproyecta la memoria compartida
	munmap(caldero, sizeof(int));
	//Se cierran los semaforos
	sem_close(full);
	sem_close(empty);
	//Se eliminan del sistema
	sem_unlink("/FULL");
	sem_unlink("/CLOSE");


	return 0;
}
