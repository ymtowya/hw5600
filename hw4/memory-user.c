#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_INT_VAL 65538

int main(int argc, char const *argv[])
{
    /* code */
    if (argc != 3) {
        printf("Invalid arguments\n");
        return -1;
    }

    const int memoMB = atoi(argv[1]);
    const int runTimeLen = atoi(argv[2]);
    const int allotLen = memoMB * 1024 * 1024;
    const int arrNum = allotLen / sizeof(int);
    const clock_t start = clock();
    
    // alloc
    int* pt = (int *) malloc(allotLen);

    printf("The pid of this process is : %d\n", getpid());

    while (clock() - start < runTimeLen * CLOCKS_PER_SEC) {
        for (int i = 0; i < arrNum; ++i) {
            *(pt + i) = (*(pt + i) + 1) % MAX_INT_VAL;
        }
    }

    printf("--Finished!--\n");

    free(pt);
    return 0;
}
