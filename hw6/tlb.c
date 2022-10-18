#include "stdio.h"
#include "stdlib.h"
#include <sys/time.h>

#define PAGESIZE 4096

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        exit(0);
    }

    struct timeval start, end;
    const int jump_time = PAGESIZE / sizeof(int);
    unsigned int page_count = atoi(argv[1]);
    unsigned int trial_count = atoi(argv[2]);

    int *memo = (int *) calloc(page_count * jump_time, sizeof(int));

    gettimeofday(&start, NULL);

    for (int i = 0; i < trial_count; ++i) {
        for (int j = 0; j < page_count; ++j) {
            memo[j * PAGESIZE / sizeof(int)] += 1;
        }
    }

    gettimeofday(&end, NULL);

    double per_time = (double) ((unsigned long) end.tv_usec - (unsigned long) start.tv_usec) / (double) (page_count * trial_count);

    printf("Average time taks %lf ns\nStart:%d\nEnd:%d\n", per_time * 1000, (int) start.tv_usec, (int) end.tv_usec);

    free(memo);
    return 0;
}












