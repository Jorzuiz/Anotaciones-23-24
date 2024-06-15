#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

// La funcion handler se declara con antelacion para que esté en la memoria de todo fork()
// es una funcion especial que se ejecuta cuando se recibe una señal desde cualquier lado
// Se ejecutará al recibir el SIGALRM del padre
void handler(int sig) {
    if (sig == SIGALRM) {   // Detecta la alarma
        printf("El hijo ha recibido una señal\n");
        kill(getpid(), SIGKILL);
    }
}

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    struct sigaction sInt;
    memset(&sInt, 0, sizeof(sInt));
    sInt.sa_handler = SIG_IGN; // Ignorar SIGINT
    sigaction(SIGINT, &sInt, NULL);

    // Crear el proceso hijo
    pid = fork();
    if (pid == -1) {
        perror("Error al crear el proceso hijo");
        exit(1);
    }

    if (pid == 0) { // Proceso hijo
        // Cambiar el ejecutable del proceso hijo por nuestra entrada
        execlp(argv[1], argv[1], NULL);
        perror("Error al cambiar el ejecutable");
        exit(1);
    } else { // Proceso padre
        struct sigaction sa;            // Estructura con la informacion de la señal
        memset(&sa, 0, sizeof(sa));     // Inicializar la estructura a 0 (tiene muchos campos, esto es importante)
        sa.sa_handler = &handler;       // Define el método asignado al handler
        sigaction(SIGALRM, &sa, NULL);  // "Instala" la señal con nuestro método

        alarm(3); // Programar una alarma para enviar una señal SIGALARM a los 5 segundos
        //kill(pid) puede enviar una señal de tipo SIGKILL

        wait(&status); // Esperar a que el hijo termine

        // Detectamos el motivo de la murte del proceso
        if (WIFSIGNALED(status)) {  // Hay un error, el proceso se muere con kill y no llega :()
            printf("El hijo terminó debido a una señal\n");
        } else if (WIFEXITED(status)) {
            printf("El hijo terminó normalmente con estado %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}