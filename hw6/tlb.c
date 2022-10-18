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
    unsigned int page_count = atoi(argv[0]);
    unsigned int trial_count = atoi(argv[1]);

    int *memo = (int *) calloc(page_count * PAGESIZE);

    gettimeofday(&start, NULL);

    for (int i = 0; i < trial_count; ++i) {
        for (int j = 0; j < page_count * jump_time; j += page_count) {
            ++memo[j];
        }
    }

    gettimeofday(&end, NULL);

    double per_time = ((double) end.tv_usec - (double) start.tv_usec) / (page_count * (double) trial_count);

    printf("Average time taks %lf\nStart:%d\nEnd:%d\n", per_time, start.tv_usec, end.tv_usec);

    free(memo);
    return 0;
}












