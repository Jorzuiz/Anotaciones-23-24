#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CLIENTS 100 // Ajustar según el aforo de la discoteca

typedef enum { NORMAL, VIP } ClientType;

// Estructura para almacenar información sobre los clientes
typedef struct {
    pthread_mutex_t lock; // Mutex para proteger la accesibilidad del aforo
    pthread_cond_t cond; // Variable de condición para esperar a que haya espacio disponible
    int count; // Contador de clientes en la discoteca
    int capacity; // Capacidad máxima de clientes en la discoteca
} Discoteca;

Discoteca discoteca;

void init_discoteca(int capacity) {
    discoteca.count = 0;
    discoteca.capacity = capacity;
    pthread_mutex_init(&discoteca.lock, NULL);
    pthread_cond_init(&discoteca.cond, NULL);
}

void destroy_discoteca() {
    pthread_mutex_destroy(&discoteca.lock);
    pthread_cond_destroy(&discoteca.cond);
}

void enter_client(ClientType type, int id) {
    pthread_mutex_lock(&discoteca.lock);
    while (discoteca.count >= discoteca.capacity) {
        if (type == NORMAL && discoteca.count < discoteca.capacity / 2) {
            pthread_cond_wait(&discoteca.cond, &discoteca.lock);
        } else {
            pthread_cond_wait(&discoteca.cond, &discoteca.lock);
        }
    }
    discoteca.count++;
    printf("Cliente %d entra en la discoteca.\n", id);
    pthread_mutex_unlock(&discoteca.lock);
}

void exit_client(int id) {
    pthread_mutex_lock(&discoteca.lock);
    discoteca.count--;
    printf("Cliente %d sale de la discoteca.\n", id);
    if (discoteca.count < discoteca.capacity / 2 && discoteca.count > 0) {
        pthread_cond_signal(&discoteca.cond);
    }
    pthread_mutex_unlock(&discoteca.lock);
}

void *client(void *arg) {
    int id = *(int *)arg;
    ClientType isvip = *(ClientType *)((char *)arg + sizeof(int));

    enter_client(isvip, id);
    sleep(1); // Simular baile
    exit_client(id);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error abriendo el archivo");
        return 1;
    }

    int M;
    fscanf(file, "%d", &M);
    fclose(file);

    init_discoteca(M);

    for (int i = 0; i < M; i++) {
        int id = i + 1;
        ClientType isvip;
        fscanf(file, "%d", &isvip);
        pthread_t thread;
        pthread_create(&thread, NULL, client, (void *)&isvip);
        pthread_detach(thread);
    }

    destroy_discoteca();

    return 0;
}