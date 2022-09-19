#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int i = 0;
    for (; i < 5; ++i) {
        int childPid = fork();
        if (childPid < 0) {
            exit(1);
        } else if (childPid == 0) {
            printf("fork_%d\n", i);
            exit(1);
        } else {
            printf("parent_%d waiting\n", i);
            wait(NULL);
            exit(1);
        } 
    }

    return 0;
}