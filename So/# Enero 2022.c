# Enero 2022
```c
#include <stdlib.h>
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