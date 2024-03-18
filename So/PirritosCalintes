#define perrito 0
#define hamburguesa 1

void conseguirPlato(int plato){
    pthread_mutex_lock(&m[plato]); // cuando coge el mutex, deja de esperar a su plato (la cola está libre)
    while(numplato[plato] == 0){
        pthread_cond_broadcast(&empty[plato]);  // Le grita al cocinero correspondiente
        pthread_cont_wait(&full[plato], &m[plato]); // espera a que el cocinero llene el plato
    }
    numplato[plato]--;
    pthread_mutex_unlock(&m[plato]);
}

servirPlato(int perrito){
    pthread_mutex_lock(&m[perrito]);
    while(numPlato[perrito]==0){
        pthread_cont_wait(&empty[perrito], &m[perrito]);
    }
    numplato[perrito]++;
    pthread_cond_broadcast(&full[perrito]);
    pthread_mutex_unlock(&m[perrito]);
}