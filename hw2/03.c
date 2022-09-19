#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int childPid = fork();
    int re = 0;
    if (childPid < 0) {
        exit(1); // failed fork
    } else if (childPid == 0) {
        // parent process
        re = waitpid(childPid, NULL, 0);
        printf("goodbye\n");
        exit(1);
    } else {
        // child
        printf("hello\n");
        exit(1);
    }
    printf("%d\n", re);
    return 0;
}