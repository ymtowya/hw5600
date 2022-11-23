#include <stdio.h>

#include "common_threads.h"

int balance = 0;

pthread_mutex_t lock;


void* worker(void* arg) {
    pthread_mutex_lock(&lock);
    balance++; // unprotected access 
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc, char *argv[]) {

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);
    pthread_mutex_lock(&lock);
    balance++; // unprotected access
    Pthread_join(p, NULL);
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
    return 0;
}
