#include <stdio.h>
#include <pthread.h>

void *print_number(void *threadnum) {
    long num = (long) threadnum;
    printf("Thread %ld\n", num);
    pthread_exit(NULL);
}

FILE *file;

void *write_to_file(void *threadnum) {
    long num = (long) threadnum;
    fseek(file, num * 5, SEEK_SET);
    fwrite(&num, 1, 5, file);
    pthread_exit(NULL);
}

pthread_mutex_t lock;
pthread_cond_t cond;

void *write_to_file_cooperative(void *threadnum) {
    long num = (long) threadnum;
    pthread_mutex_lock(&lock);
    while(feof(file)) {
        pthread_cond_wait(&cond, &lock);
    }
    
    printf("Thread %ld\n", num);
    fseek(file, num * 5, SEEK_SET);
    fwrite(&num, 1, 5, file);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    long tids[10];
	
	//b
    //file = fopen("output.txt", "wb");

	//c
	file = fopen("output.txt", "wb+");
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);


    for(long i = 0; i < 10; i++) {
        tids[i] = i;
        //pthread_create(&threads[i], NULL, print_number, &tids[i]);
		//b
		//pthread_create(&threads[i], NULL, write_to_file, &tids[i]);
		//c
	    pthread_create(&threads[i], NULL, write_to_file_cooperative, &tids[i]);
    }

    for(long i = 0; i < 10; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    fclose(file);

    return 0;
}