#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>7

void print_graph(struct task tasks[], int n)
{
    int i,j;
    for (i = 0; i < n; i++) {
    if (!tasks[i].valid)
    continue;
    printf("%d: ", tasks[i].id);
    for (j = 0; j < n; j++)
    if (tasks[i].next[j])
    printf("%d ", j);
    printf("\n");
    }
}

int main(int argc, char *argv[])
{
	int opt;
	int flagN=0; // - n
	int flagE=0; // -e
	off_t offset=0; //N value

	while((opt = getopt(argc, argv, "n:e")) !=-1){
		switch(opt){
			case 'n':
				flagN=1;
				offset= atoi(optarg);
			break;

			case 'e':
				flagE=1;
			break;

			default:
			  fprintf(stderr, "Uso: %s [-n N] [-e] fichero\n", argv[0]);
			break;
		}
	}

	 // Verificar que se proporcionó el nombre del fichero
    if (optind >= argc) {
        fprintf(stderr, "Se espera el nombre del fichero como argumento\n");
        exit(EXIT_FAILURE);
    }

	if(flagE){
		struct stat stat_buffer;
		if(stat(argv[optind], &stat_buffer)==-1){

		}
		offset=stat_buffer.st_size - offset;

	}

	

	return 0;
}