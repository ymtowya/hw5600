#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    int childPid = fork();
    
    if (childPid < 0) {
        exit(1);
    } else if (childPid == 0) {
        close(STDOUT_FILENO);
        printf("Child print test\n");
        exit(1);
    } else {
        wait(NULL);
    }

    return 0;
}