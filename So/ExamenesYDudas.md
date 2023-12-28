# Clase del final

# 2022
|Proceso|0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|P1(5,3)|x1|x1|||||x2|x2|x2|0|0|0|x1|x1|||||x2|x2|x2|
|P2(4,3)|||x1|x1||||||x2|x2|0|0|0|x1|x1||||||
|P3(5,4)|||||x1|x1|||||x2|||||x2|x2|0|0|0|
|L1|p2||p3|p3||||||||||||||||||
|RR(2)|p3|||||||||||||||||||||
|L2|||p1|p1|p1|p1|p2|p2|p2|p3|p3||p3|p3|p3|p3|p1|p1|p2|p2|p2|
|RR(3)|||||p2|p2|p3|p3|p3|||||||p1|p1|p2|p2|||

>Evento de planificacion en 10-11
<>11-12 Sale de ES en 11-12 y entra en cola siendo más prioritaria robando el proceso e insertando P3 en cola de nivel 2

Porcentaje de CPU 
- $\frac{20}{21}100$

Tiempos de espera
- P1=8
- P2=12
- P3=13

# 2020

```c
#define SIZEBUF 10
int rd_idx=0;
int wd_idx=0;
int buffer[SIZEBUF];
// Sempahore definitions
sem_t p1, p2, huecos, elem; 
//em_init(nombresemaforo, pthread, valor incial);
sem_init(&m, 0,1);   
sem_init(&huecos, 0,SIZEBUF);
sem_init(&elem, 0,0);
```

```c
void consumer ();{
    int i =0, item;
    for (i=0; i<60;i++){

        sem_init(&elem);
        item = buffer[rd_idx];
        rd_idx=(rd_idx+1)%SIZEBUF;
        sem_post(&huecos);

        do_something_with(item);
    }
}
```

```c
void producer1(){
    int i =0, item;
    for(i=0;i<20;i++){

        item=generate_random_num();
    
        sem_wait(&p1);  // Espera a turno
        sem_wait(&huecos);  // Espera a hueco

        // Inserta
        buffer[wr_idx]=item;
        wr_idx=(wr_idx+1)%SIZEBUF;

        sem_post($elem);
        sem_post($p2);
    }
}
```

```c
void producer2(){
    int i =0, item;
    for(i=0;i<20;i++){

        item=generate_random_num();
    
        sem_wait(&p2);  // Espera a turno
        sem_wait(&huecos);  // Espera a hueco

        // Inserta
        buffer[wr_idx]=item;
        wr_idx=(wr_idx+1)%SIZEBUF;

        sem_post($elem);
        if(i%2==0)
            sem_post($p2);
        else
        sem_post($p1);
    }
}
```

# 2022 Enero

```c
1 #include <stdlib.h>
2 #include <stdio.h>
3 #include <pthread.h>
4 #include <string.h>
5
6 #define BUFFER_SIZE 4096
7 char buffer[BUFFER_SIZE];
8
9 void *producer(void * arg){
10 int index;
11 // producer operations
12 return NULL;
13 }
14
15 void *consumer(void * arg){
16 int index;
17 // consumer operations
18 return NULL;
19 }
20
21 int main()
22 {
23 pid_t pid;
24 FILE *fileOrigin, *fileDestiny;
25 char *nameOrigin = "shakespeare.txt";
26 char *mem_origin, *mem_destiny;
27
28 fileOrigin = open(nameOrigin, O_RDONLY);
29 mem_origin = mmap(0, BUFFER_SIZE, PROT_READ, MAP_SHARED, fileOrigin, 0);
30 if ( (pid=fork()) == -1) {
31 printf("ERROR.\n");
32 exit(-1);
33 }
34 else if (pid==0) {
35 pthread_t th_producer, th_consumer;
36 pthread_create(&th_producer, NULL, (void *)producer, NULL);
37 pthread_create(&th_consumer, NULL, (void *)consumer, NULL);
38 pthread_join(th_producer, NULL);
39 pthread_join(th_consumer, NULL);
40 }
41 else {
42 char *nameDestiny = "copy_shakespeare.txt";
43
44 fileDestiny = open(nameDestiny, O_WRONLY);
45 mem_destiny = mmap(0, BUFFER_SIZE, PROT_WRITE, MAP_PRIVATE, fileDestiny, 0);
46 memcpy(buffer, mem_origin, BUFFER_SIZE);
47 memcpy(mem_destiny, buffer, BUFFER_SIZE); // POINT A
48 fclose(fileDestiny);
49 fclose(fileOrigin);
50 munmap(mem_origin, BUFFER_SIZE);
51 munmap(mem_destiny, BUFFER_SIZE);
52
53 while (wait(NULL) != -1) ;
54 }
55 return 0; // POINT B
56 }
```
### A
|Variable/Macro|Región Proceso Padre|Región Proceso Hijo|Privado/COmpartido|Ejecutable(Si/No)|
|---|---|---|---|---|
|BUFFER_SIZE|-|-|-|NO|
|buffer|datos|datos|Privado|NO|
|meme_origin|stack|stack|Privado|NO|
|mem_destiny|stack|stack|Privado|NO|
|index|-|stack de los hijos|Privada|NO|

>El proceso padre no ejecuta las funciones en index

### B
1. Punto A
- Ppadre: 
Reg datos
Reg codigo
reg pila
reg de ficheros proyectados (Compartida)
reg de ficheros protectados "Destiny"

- PHijo
Asumiendo que el hijo está bloqueadoen la linea 38 a la espera de que termine el productor
reg datos
reg codigo
reg pila
reg de fichero proyectado (compartido)
+2 regiones de memoria para las pilas de los hilos creados

2. Punto B
- Padre igual que el punto A excepto que ha eliminado las dos regiones de Fich proyectados
-Hijo: se ha eiminado todo su espacio de direcciones


### C 
7 paginas de codigo + 3 de datos

### D
1 pagina