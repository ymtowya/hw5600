
#include "./common_threads.h"
#include <stdio.h>
#include <stdlib.h>   // malloc, free
#include <sys/time.h> // gettimeofday
#include <unistd.h>  

long getInterval(struct timeval start, struct timeval end) {
    long seconds = end.tv_sec - start.tv_sec;
    long micro_seconds = end.tv_usec - start.tv_usec;

    if (micro_seconds < 0)
    {
        seconds -= 1;
    }

    long total_micro_seconds = (seconds * 1000000) + abs(micro_seconds);
    return total_micro_seconds;
}

int curr = 0;

typedef struct node_t {
    int key;
    pthread_mutex_t lock;
    struct node_t *next;
} node_t;


typedef struct list_t {
    node_t *head;
    pthread_mutex_t glock;
} list_t;


void List_Init(list_t *L) {
    L->head = NULL;
    pthread_mutex_init(&L->glock, NULL);
}

void List_Insert(list_t *L, int key) {
    // synchronization not needed
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL) {
        perror("malloc");
        return;
    }
    new->key = key;
    pthread_mutex_init(&new->lock, NULL);

    // just lock critical section
    pthread_mutex_lock(&L->glock);
    new->next = L->head;
    L->head = new;
    pthread_mutex_unlock(&L->glock);
}

int List_Lookup(list_t *L, int key) {
    int rv = -1;
    
    node_t *curr = L->head;
    pthread_mutex_lock(&curr->lock);
    while (curr) {
        if (curr->key == key) {
            rv = 0;
            pthread_mutex_unlock(&curr->lock);
            break;
        }
        pthread_mutex_t *tempLock = &curr->lock;
        curr = curr->next;
        if (curr)
            pthread_mutex_lock(&curr->lock);
        pthread_mutex_unlock(tempLock);
    }

    return rv; // now both success and failure
}

void *doCheck(void *arg) {
    list_t *ls = (list_t *)arg;
    List_Lookup(ls, 0);
    return NULL;
}

int main(int argc, char const *argv[])
{
    struct timeval time_1, time_2;

    pthread_t p1, p2, p3, p4;

    list_t myList;
    List_Init(&myList);
    for (int i = 0; i < 10000; i++) {
        List_Insert(&myList, i);
    }

    gettimeofday(&time_1, NULL);

    Pthread_create(&p1, NULL, doCheck, &myList);
    Pthread_create(&p2, NULL, doCheck, &myList);
    Pthread_create(&p3, NULL, doCheck, &myList);
    Pthread_create(&p4, NULL, doCheck, &myList);

    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    Pthread_join(p3, NULL);
    Pthread_join(p4, NULL);

    gettimeofday(&time_2, NULL);

    printf("interval: %ld\n",
        (long) getInterval(time_1, time_2));
    
    return 0;
}






