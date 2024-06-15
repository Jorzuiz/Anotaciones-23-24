#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_COMMANDS 20
#define MAX_CHARS_LINE 128

/**
 * Launchs a bash command creating a new
 * child process that execs /bin/bash.
 * 
 * The function returns the pid of the 
 * newly created process, and does not wait
 * for the process to complete. 
*/
pid_t run_command(const char* command){
    pid_t pid = -1;

    /* To be completed ... */
	pid = fork();

	if (pid == 0){	// Hijo
		// por algun motivo la barra del bin es importante y el bash tambien

		execl("/bin/bash", "bash", "-c", command, NULL);
		// Cualquier cosa despues de un execl es un fallo al cambiar el mapa del hijo
		perror("Exec fallido?/n");
		exit(EXIT_FAILURE);
	}
	else if (pid>0) // Padre PID>0
	{
		return pid;
		//while(pid!=wait(NULL)); // FOKIN WITCHCRAFT MATE
		//printf("@@ Command terminated: PID%d Command %s", pid, command);
	}else{
		perror("Fallo del fork/n");
		exit(EXIT_FAILURE);
	}
}

void run_from_file(const char* filename){
	
	FILE* file = fopen(filename, "r");
	if (!file)
    {
        perror("Error opening file");
        return;
    }

	pid_t pid = -1;
	
	char line[1024];
	while (fgets(line, sizeof(line), file) != NULL){
		// fgets añade un salto de linea, hay que eliminarlo??
		// no da problema
		//line[strcspn(line, "\n")] = 0;
		printf("@@ Running command: %s", line);
		pid = run_command(line);
		int status = 0;
		waitpid(pid, &status, 0);
	}

	fclose(file);
	return;
}

void run_parallel(const char* filename){
	
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error de apertura\n");
        return;
    }

	pid_t command_list[MAX_COMMANDS];
	int command_count = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {

        pid_t pid = run_command(line);
        command_list[command_count] = pid;
        command_count++;

        // Info ANTES de ejecutar
        printf("@@ Running command in parallel #%d: %s", command_count, line);
    }

    // Esperar a que todos los comandos terminen
    for (int i = 0; i < command_count; i++) {
		int status = 0;
        waitpid(command_list[i], &status, 0);
        printf("@@ Command #%d terminated (pid: %d, status: %d)\n", i + 1, command_list[i], WEXITSTATUS(status));
    }
}

int main(int argc, char* argv[]){
	
	int opt;

	char* commands;
	char* input_file;
	bool x_option = false;
	bool s_option = false;
	bool b_option = false;
	
	while ((opt = getopt(argc, argv, "hx:s:b")) != -1)
	{
		switch (opt)
		{
		case 'h':
            printf("Usage: %s [ -x <command> | -s <script> | -b]\n", argv[0]);
			break;
        /* To be completed ... */
		case 'x':
			x_option = true;
			commands = optarg;
			break;
		case 's':
			s_option = true;
			input_file = optarg;
			break;
		case 'b':
			b_option = true;
			break;
		default:
			exit(2);
		}
	}

    /* To be completed ... */

	if(x_option){
		run_command(commands);
	}
	else if(b_option){
		if(s_option){
			run_parallel(input_file);
		}else 
		printf("Error en la opcion -b, no se ha especificado el archivo de entrada con -s\n");
	}
	else if(s_option){
		run_from_file(input_file);
	}

    return 0;
}