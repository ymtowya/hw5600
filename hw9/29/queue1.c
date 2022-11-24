
#include "./common_threads.h"
#include <stdio.h>
#include <stdlib.h>   // malloc, free
#include <sys/time.h> // gettimeofday
#include <unistd.h>  

#define TIMES 10000
#define NUMS 3

typedef struct node_t {
    int value;
    struct node_t *next;
} node_t;

typedef struct queue_t {
    node_t *head;
    node_t *tail;
    pthread_mutex_t gLock;
} queue_t;

void queue_init(queue_t *q) {
    node_t *tmp = malloc(sizeof(node_t));
    tmp->next = NULL;
    q->head = tmp;
    q->tail = tmp;
    pthread_mutex_init(&q->gLock, NULL);
}

void queue_enter(queue_t *q, int value) {
    node_t *tmp = malloc(sizeof(node_t));
    assert(tmp != NULL);
    tmp->value = value;
    tmp->next = NULL;

    pthread_mutex_lock(&q->gLock);
    q->tail->next = tmp;
    q->tail = tmp;
    pthread_mutex_unlock(&q->gLock);
}

int queue_poll(queue_t *q, int *value) {
    pthread_mutex_lock(&q->gLock);
    node_t *tmp = q->head;
    node_t *newHead = tmp->next;
    if (newHead == NULL) {
        pthread_mutex_unlock(&q->gLock);
        return -1; // queue was empty
    }
    *value = newHead->value;
    q->head = newHead;
    pthread_mutex_unlock(&q->gLock);
    free(tmp);
    return 0;
}

void* doAdd(void* arg) {

    queue_t* q = (queue_t *) arg;
    for (int i = 0; i < TIMES; ++i) {
        queue_enter(q, i);
    }    
    return NULL;
}

void* doOut(void* arg) {
    int tmp = 0;
    queue_t* q = (queue_t *) arg;
    for (int i = 0; i < TIMES; ++i) {
        queue_poll(q, &tmp);
    }    
    return NULL;
}

int main(int argc, char const *argv[])
{
    struct timeval time_1, time_2;

    pthread_t p[NUMS * 2];
    
    for (int total = 0; total < NUMS; ++total) {
        queue_t q;
        queue_init(&q);
        gettimeofday(&time_1, NULL);

        for (int i = 0; i <= total; ++i) {
            Pthread_create(&p[i], NULL, doAdd, &q);
            Pthread_create(&p[i + NUMS], NULL, doOut, &q);
        }

        for (int i = 0; i <= total; ++i) {
            Pthread_join(p[i], NULL);
            Pthread_join(p[i + NUMS], NULL);
        }

        gettimeofday(&time_2, NULL);

        printf("Number of Thread is : %d\n", total * 2);
        doOut(&q);

        printf("interval: %ld\n",
            time_2.tv_usec - time_1.tv_usec);
            
    }


    return 0;
}


