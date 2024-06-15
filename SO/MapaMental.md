# Resumen general

$$
\boxed{Preprocesado}\rightarrow
\boxed{Compilado}\rightarrow
\boxed{Ensamblado}\rightarrow
\boxed{Enlazado}\\
$$

***

Linea de comandos:
>gcc -E

Genera preprocesado, archivo .i, incluye y substituye las llamadas a librerias estáticas en el código
Por ejemplo, llamada a `min(a,b)` se sustituye por `a<b?a:b`
***
$$\boxed{HERE\quad BE\quad DRAGONS}$$
***
>Se puede codificar elementos usando bytes en archivos, pueden ser binarios o texto plano. Los binarios se codifican en hexadecimal y pueden tener valores de 0 a 255 (Los valores de 0 a 16 son los valores de 0 a 9 y las letras de la A a la F. Lo que visualmente son dos valores Hexadecimales como D5 son 256 posibles valores) usando caracteres que se ven como `&` `@` o `A` que equivalen a valores. 
>La escritura de tipos es más rápida con valores de multiples bytes, por ejemplo: el numero int 82642 se puede escribir con los digitos 8-2-6-4-2 ocupando 5 bytes en texto plano o se puede escribir 00-01-42-D2 (0-1-66-210) que son 4 bytes.

- Char = 1 byte ($2^8$ valores $\simeq$ 256)
- Int = 4 bytes ($2^32$ valores $\simeq$ 4,294,967,295)
- `sizeof(char* cosas)` devuelve 4 porque hemos preguntado el tamaño del puntero
- `sizeof(char[] cosas)` devolverá 21 si por ejemplo hay 21 elementos porque pregunta el tamaño del array
***
`make` corre el archivo makefile
La regla .PHONY permite correr el comando `make clean` para limpiar los archivos compilados con el gcc
Para correr cualquier archivo ponemos `./` delante
>Me ha surgido un problema gracioso por intentar correr un script que habia hecho en windows. Parece dar errores por el final de linea mal parseado(^M), se puede instalar dos2unix rapidamente para cambiarlo, pero como pase durante el examen casi que es mas fácil reescribir el script.
***
> Se puede abrir archivos con open() o con fopen(), este ultimo es más elaborado y tiene protecciones con el File Descritor `FILE* stream`, el otro es a más bajo nivel y no proteje de escritura en diferentes procesos.

>`fgets(char Buffer, int Length, FILE* file)` -> Carga en el buffer un máximo de size-1 o el siguiente salto de linea. PONE UN BYTE NULO AL FINAL '\0'
```c
char line[MAXLEN_LINE_FILE];
while (fgets(line, MAXLEN_LINE_FILE, file) != NULL)
```

>`fread(Buffer, sizeof(tipo), lengh, file)` -> Con el stream file, lee lenght elementos de tamaño sizeof y los carga en el buffer. SE PUEDE USAR POR EJEMPLO PARA STRUCTS pero deben de haberse escrito como un binario.*/
```c
// Dato inicial del fichero (4 bytes)
int num_entries;
fread(&num_entries, 4, 1, file);

student_t student;
fread(&student, sizeof(student_t), 1, file);
```

> La diferencia entre escribir/leer en binario y normal es que el normal usa chars y hay que parsear las cosas a mano mientras que el binario se pueden meter cosas como structs sin preocuparse mucho.

>fscanf(FILE, formato, elemento1, elemento2, ...) -> Permite leer del input y parsear a un formato
```c
int num_entries;
fscanf(input, "%d", &num_entries);

student_t student;
fscanf(input, "%d:%9[^:]:%19[^:]:%19[^\n]",
            &student.student_id, student.NIF,
            student.first_name, student.last_name);
```        
