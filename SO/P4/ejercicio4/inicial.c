#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    int fd, i, pos;
    char c;
    char buffer[6];

    fd = open("output.txt", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);

    // Cuestion A
    write(fd, "00000", 5);
    for (i = 1; i < 10; i++)
    {
        // Cuestion B
        //write(fd, "00000", 5); // Padre escribiendo los 0 iniciales; Solo habia que bajar la linea a antes del fork
        
        pos = lseek(fd, 0, SEEK_CUR); // Obtener la posición actual del cursor en el fichero
        if (fork() == 0)
        {
            // Al parecer una maanera de hacer esto es modificar el write para que no sea bloqueante
            fcntl(fd, F_GETFL, 0);              // Obtener flags actuales del fd
            int flags = fcntl(fd, F_GETFL, 0) | O_NONBLOCK; // Cambia el fd a no bloqueante
            fcntl(fd, F_SETFL, flags);          // Aplica los nuevos flags

            /* Child */
            sprintf(buffer, "%d", i * 11111);   // Añade al final del buffer
            lseek(fd, pos, SEEK_SET);           // Pone el cursor en pos
            write(fd, buffer, 5);
            close(fd);  // Cierra SU fd, no e global
            exit(0);    // El hijo termina
        }
        else
        {
            /* Parent */
            // Cuestion A parece pedir que no se pisen
            lseek(fd, 5, SEEK_CUR);
            // Cuestion B parece implicar sincronizacion
            //wait(NULL); // El padre espera al hijo antes de crear uno nuevo
        }
    }

    // Wait for all children to finish
    while (wait(NULL) != -1);

    lseek(fd, 0, SEEK_SET);
    printf("File contents are:\n");
    while (read(fd, &c, 1) > 0)
        printf("%c", (char)c);
    printf("\n");
    close(fd);
    exit(0);
}