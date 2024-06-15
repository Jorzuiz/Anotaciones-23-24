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
- Char = 1 byte ($2^8$ valores $\simeq$ 256)
- Int = 4 bytes ($2^32$ valores $\simeq$ 4,294,967,295)
- `sizeof(char* cosas)` devuelve 4 porque hemos preguntado el tamaño del puntero
- `sizeof(char[] cosas)` devolverá 21 si por ejemplo hay 21 elementos porque pregunta el tamaño del array
***
`fgetc(FILE* file)` -> lee un caracter de un stream y lo parsea de unsigned char a int (Usado para avanzar en un archivo hasta llegar al final '\0')
`fread(char* buffer, 1, sizeof(char* buffer), FILE* file)` -> Lee sizeof veces el tamaño bytes del archivo file y lo carga en buffer, devuelve el numero de lecturas correctas. (El 1 son los bytes de un unsigned char, si fuese int serian 4)ç
