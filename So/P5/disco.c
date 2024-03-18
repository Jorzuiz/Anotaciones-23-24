#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CAPACITY 5
#define VIPSTR(vip) ((vip) ? "  vip  " : "not vip")

pthread_mutex_t mutex;
pthread_cond_t empty;

int turno;	// COmun a hilos
int turnoVIP;
int colaVIP;

int maquinaTicket;
int maquinaticketVIP;

void enter_normal_client(int id)
{
	int myTicket;

	pthread_mutex_lock(&mutex);
	myTicket=maquinaTicket;
	maquinaTicket++;

	// esperamos a que haya hueco, sea nuestro turno y no hayan vips delante
	while (aforo >= CAPACITY || myTicket != turno || colaVIP > 0)
		pthread_cond_wait(&empty, &mutex);

	// Actualizamos el turno y el numero de gente dentro
	aforo++;
	turno++;
	pthread_broadcast(&empty);	// Puede entrar el siguiente
	pthread_mutex_unlock(&mutex);
}c

void enter_vip_client(int id)
{

	int myTicket;

	pthread_mutex_lock(&mutex);
	myTicket=maquinaticketVIP;
	maquinaticketVIP++;

	// esperamos a que haya hueco, sea nuestro turno y no hayan vips delante
	while (aforo >= CAPACITY || myTicket != turnoVIP)
		pthread_cond_wait(&empty, &mutex);

	// Actualizamos el turno y el numero de gente dentro
	aforo++;
	turnoVIP++;
	pthread_broadcast(&empty);	// Puede entrar el siguiente
	pthread_mutex_unlock(&mutex);
}

void dance(int id, int isvip)
{
	printf("Client %2d (%s) dancing in disco\n", id, VIPSTR(isvip));
	sleep((rand() % 3) + 1);
}

void disco_exit(int id, int isvip)
{
	pthread_mutex_lock(&mutex);
	aforo--;
	phtread_broadcast(&empty);
	pthread_mutex_unlock(&mutex);
}

void *client(void *arg)
{

    if ( isvip )
        enter_vip_client( ... );
    else
        enter_normal_client( ... );
    dance( ... );
    exit_client( ... );

}

int main(int argc, char *argv[])
{
	int aforo = 0;
	
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_wait_init(&empty, NULL);

	pthread_t clientes[5];

	pthread_mutex_destroy(&mutex);

	return 0;
}
