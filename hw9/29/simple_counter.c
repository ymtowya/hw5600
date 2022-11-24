#include "./common_threads.h"
#include <stdio.h>
#include <stdlib.h>   // malloc, free
#include <sys/time.h> // gettimeofday
#include <unistd.h>  

#define LOOPS 10000

typedef struct counter_t {
  pthread_mutex_t lock;
  int value;
} counter_t;

void init(counter_t *c) {
    c->value = 0;
    Pthread_mutex_init(&c->lock, NULL);
}

void increment(counter_t *c) {
    Pthread_mutex_lock(&c->lock);
    c->value++;
    Pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c) {
    Pthread_mutex_lock(&c->lock);
    int tmp = c->value;
    Pthread_mutex_unlock(&c->lock);
    return tmp;
}

void* doAdd(void* arg) {
    counter_t *cc = (counter_t *)arg;
    for (int i = 0; i < LOOPS; ++i) {
        increment(cc);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    struct timeval time_1, time_2;

    counter_t c1;
    init(&c1);

    pthread_t p1;//, p2;//, p3, p4;
    
    gettimeofday(&time_1, NULL);

    Pthread_create(&p1, NULL, doAdd, &c1);
    //Pthread_create(&p2, NULL, doAdd, &c1);
    // Pthread_create(&p3, NULL, doAdd, &c1);
    // Pthread_create(&p4, NULL, doAdd, &c1);

    Pthread_join(p1, NULL);
    //Pthread_join(p2, NULL);
    // Pthread_join(p3, NULL);
    // Pthread_join(p4, NULL);

    gettimeofday(&time_2, NULL);

    printf("Final Value is : %d\n", get(&c1));

    printf("time1 : %ld\ntime2 : %ld\ninterval: %ld\n",
        time_1.tv_usec, time_2.tv_usec, time_2.tv_usec - time_1.tv_usec);

    return 0;
}
