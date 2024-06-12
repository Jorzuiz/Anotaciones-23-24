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
`make` corre el archivo makefile
La regla .PHONY permite correr el comando `make clean` para limpiar los archivos compilados con el gcc
Para correr cualquier archivo ponemos `./` delante
>Me ha surgido un problema gracioso por intentar correr un script que habia hecho en windows. parece dar errores por el final de linea mal parseado, se puede instalar dos2unix rapidamente para cambiarlo, pero como pase durante el examen casi que es mas facil reescribir el script.
***