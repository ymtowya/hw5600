#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    int childPid = fork();
    int re = wait(NULL);

    if (childPid < 0) {
        exit(1);
    } else if (childPid == 0) {
        printf("Child: %d\n", re);
    } else {
        printf("Parent: %d\n", re);
    }

    return 1;
}