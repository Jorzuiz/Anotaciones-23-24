#include <stdio.h>
#include <stdlib.h>

/** Loads a string from a file.
 *
 * file: pointer to the FILE descriptor
 *
 * The loadstr() function must allocate memory from the heap to store
 * the contents of the string read from the FILE.
 * Once the string has been properly built in memory, the function returns
 * the starting address of the string (pointer returned by malloc())
 *
 * Returns: !=NULL if success, NULL if error
 */
char* loadstr(FILE* input) {

	// Determina la posicion actual en el archivo
    long pos = ftell(input);	
    long length = 0;

	// Calcula el tamaño total del fichero
	while (fgetc(input) != '\0') {
        length++;
    }

    // Devuelve el descriptor al inicio
    fseek(input, pos, SEEK_SET);

    // Reserva memoria para el fichero + `\0` 
    char* str = (char*)malloc(length + 1);
    if (!str) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Carga el contenido del archivo en el buffer, terminado en `/0`
    fread(str, 1, length + 1, input);

    return str;
}

void read_strings( FILE* file){

	while(!feof(file)){
		char* line = loadstr(file);
		printf("%s\n", line);
		free(line);
		if(feof(file)){
			break;
		}
	}
}

int main(int argc, char* argv[]){
	if(argc != 2){
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
	}

	FILE* file = fopen(argv[1], "rb");

	if(!file){
		perror("File not existent");
		exit(1);
	}
	
	read_strings(file);
	return 0;
}