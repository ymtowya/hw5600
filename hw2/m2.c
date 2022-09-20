#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sched.h>
#include <stdbool.h>

int main() {
    const int loops  = 10;
    struct timeval start, end;

    cpu_set_t my_set;
    CPU_ZERO(&my_set);
    CPU_SET(0, &my_set);
    sched_setaffinity(0, sizeof(cpu_set_t), &my_set);

    int p1[2], p2[2];
    char msg1[128], msg2[128];
    if (pipe(p1) == -1 || pipe(p2) == -1) {
        exit(1);
    }

    int pid = fork();
    if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &my_set) == -1) {
       exit(-1);
    }

    if (pid < 0) {
        exit(1);
    } else if (pid == 0) {
        // child
        gettimeofday(&start, NULL);
        for (int i = 0; i < loops; ++i) {
            read(p2[0], msg1, 0);
            write(p1[1], msg2, 0);  
        }
        gettimeofday(&end, NULL);
    } else {
        // parent
        gettimeofday(&start, NULL);
        for (int i = 0; i < loops; ++i) {
            write(p2[1], msg1, 0);
            read(p1[0], msg2, 0);
        }
        gettimeofday(&end, NULL);
    }

    int durationTotal = end.tv_usec - start.tv_usec;
    printf("Start: %d - End: %d\nTotal Duration: %d\nAvg Duration: %f\n", start.tv_usec, end.tv_usec, durationTotal, ((0.0 + durationTotal) / loops));

    return 0;
}