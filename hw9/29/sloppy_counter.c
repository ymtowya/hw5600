#include "./common_threads.h"
#include <stdio.h>
#include <stdlib.h>   // malloc, free
#include <sys/time.h> // gettimeofday
#include <unistd.h>  

#define LOOPS 1000000
#define NUMS 4
int THRESHOLD = 10;

typedef struct counter_t {
    int global;
    pthread_mutex_t glock;
    pthread_mutex_t lock[NUMS];
    int local[NUMS];
    int threshold;
} counter_t;

typedef struct thread_info {
    int id;
    counter_t *c;
} thread_info;

void init(counter_t *c) {
    c->global = 0;
    c->threshold = THRESHOLD;
    Pthread_mutex_init(&c->glock, NULL);
    for (int i = 0; i < NUMS; ++i) {
        c->local[i] = 0;
        Pthread_mutex_init(&c->lock[i], NULL);
    }
}

void increment(counter_t *c, int id) {
    Pthread_mutex_lock(&c->lock[id]);
    ++(c->local[id]);
    if (c->local[id] >= c->threshold) {
        Pthread_mutex_lock(&c->glock);
        c->global += c->local[id];
        Pthread_mutex_unlock(&c->glock);
        c->local[id] = 0;
    }
    Pthread_mutex_unlock(&c->lock[id]);
}

int get(counter_t *c) {
    Pthread_mutex_lock(&c->glock);
    int tmp = c->global;
    Pthread_mutex_unlock(&c->glock);
    return tmp;
}

void* doAdd(void* arg) {
    thread_info *th = (thread_info *)arg;
    for (int i = 0; i < LOOPS; ++i) {
        increment(th->c, th->id);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    struct timeval time_1, time_2;

    counter_t c1;
    init(&c1);

    thread_info t[NUMS];
    for (int i = 0; i < NUMS; ++i) {
        t[i].c = &c1;
        t[i].id = i;
    }

    for (int now_thres = 2; now_thres < 36; now_thres *= 2) {
        THRESHOLD = now_thres;
        pthread_t p[NUMS];
        printf("\n\nThreshold is : %d\n", THRESHOLD);
        for (int total = NUMS - 1; total < NUMS; ++total) {
            init(&c1);
            gettimeofday(&time_1, NULL);

            for (int i = 0; i <= total; ++i) {
                Pthread_create(&p[i], NULL, doAdd, &t[i]);
            }

            for (int i = 0; i <= total; ++i) {
                Pthread_join(p[i], NULL);
            }

            gettimeofday(&time_2, NULL);

            // printf("\nFinal Value is : %d\n", get(&c1));

            printf("interval: %ld\n",
                time_2.tv_usec - time_1.tv_usec);
            
        }
    }

    return 0;
}
