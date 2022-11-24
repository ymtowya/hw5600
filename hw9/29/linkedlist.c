
#include "./common_threads.h"
#include <stdio.h>
#include <stdlib.h>   // malloc, free
#include <sys/time.h> // gettimeofday
#include <unistd.h>  

int curr = 0;

typedef struct node_t {
    int key;
    struct node_t *next;
} node_t;


typedef struct list_t {
    node_t *head;
    pthread_mutex_t lock;
} list_t;


void List_Init(list_t *L) {
    L->head = NULL;
    pthread_mutex_init(&L->lock, NULL);
}

void List_Insert(list_t *L, int key) {
    // synchronization not needed
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL) {
        perror("malloc");
        return;
    }
    new->key = key;

    // just lock critical section
    pthread_mutex_lock(&L->lock);
    new->next = L->head;
    L->head = new;
    pthread_mutex_unlock(&L->lock);
}

int List_Lookup(list_t *L, int key) {
    int rv = -1;
    pthread_mutex_lock(&L->lock);
    node_t *curr = L->head;
    while (curr) {
        if (curr->key == key) {
            rv = 0;
            break;
        }
        curr = curr->next;
    }
    pthread_mutex_unlock(&L->lock);
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

    printf("time1 : %ld\ntime2 : %ld\ninterval: %ld\n",
        time_1.tv_usec, time_2.tv_usec, time_2.tv_usec - time_1.tv_usec);
    
    return 0;
}






