#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int childPid = fork();

    if (childPid < 0) {
        exit(1); // failed fork
    } else if (childPid == 0) {
        // parent process
        int re = waitpid(childPid, NULL, 0);
        printf("goodbye");
        exit(1);
    } else {
        // child
        print("hello");
        exit(1);
    }
    return 0;
}