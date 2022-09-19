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
        printf("Parent: %d", re);
    } else {
        printf("Child: %d", re);
    }

    return 1;
}