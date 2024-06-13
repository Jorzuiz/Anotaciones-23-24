#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>

#define NUMITER 3 //Cuantas raciones come el salvaje en total

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
SALVAJES:
Este programa intentara abrir los recursos compartidos por cocinero.c. Si no los encuentra, avisa con un mensaje de
error avisando al usuario de que se debe ejecutar primero el programa cocinero. Cuando haya abierto los recursos
ejecutara la funcion salvajes() que intentara comer NUMITER veces del caldero y luego acabara. Se pueden crear tantos
procesos de este programa como se quiera.
*/

//Variables globales que se obtienen de memoria compartida
sem_t* full;
sem_t* empty;
int* caldero;

int getServingsFromPot(void)
{
	return 1; //Coje 1 racion
}

void eat(int servingsLeft)
{
	unsigned long id = (unsigned long) getpid();
	printf("Savage %lu eating\n", id);

	if(servingsLeft == 0){
		printf("Savage has eaten enough\n");
	}
	else{
		printf("Remaining food to eat enough: %d\n", servingsLeft);
	}
	sleep(rand() % 5);
}

void savages(void)
{
	for(int i = 1; i<=NUMITER; i++){
		sem_wait(full); //Se quedan esperando el resto
		(*caldero) -= getServingsFromPot();
		printf("Servings left in the pot: %d\n",(*caldero));

		if((*caldero)==0){
			sem_post(empty); //Si esta vacio avisa al cocinero
		}
		else{
			//Se avisa de que aun queda comida para que el resto de salvajes salga del wait
			sem_post(full);
		}
		//El salvaje come
		eat(NUMITER-i);
	}
}

int main(int argc, char *argv[])
{
	int shared;
	if((shared = shm_open("/CALDERO", O_RDWR, S_IRUSR | S_IWUSR))==-1){
		perror("shm_open salvajes. Cocinero must be executed first\n");
		exit(EXIT_FAILURE);
	}

	//Los salvajes pueden leer y escribir, por eso se ponen esas flags de proteccion
	caldero = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shared, 0);

	//No hace falta darle valores a los semaforos ya que se los dio cocinero.c antes
	if((full = sem_open("/FULL", 0))==SEM_FAILED){
		perror("sem_open failed to open /FULL\n");
		exit(EXIT_FAILURE);
	}
	empty = sem_open("/EMPTY", 0);

	//A partir de aqui se ejecuta todo
	savages();

	shm_unlink("/CALDERO");
	//Se desproyecta el objeto de memoria compartida
	munmap(caldero, sizeof(int));
	//Se cierran los semaforos pero es cocinero.c quien los borra con unlink
	sem_close(full);
	sem_close(empty);

	return 0;
}
