#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    const int msg_size = 16;
    int fds[2];
    int pipe1 = pipe(fds);
    if (pipe1 < 0) {
        exit(1);
    }

    int childPid2 = 0;
    int childPid1 = fork();

    char msg[128];
    
    if (childPid1 < 0) {
        exit(1);
    } else if (childPid1 == 0) {
        printf("child 1\n");
    } else {
        int childPid2 = fork();
        if (childPid2 < 0) {
            exit(1);
        } else if (childPid2 == 0) {
            // p2
            printf("child 2\n");
            dup2(pipe1[0], STDIN_FILENO);
            gets(msg);
            printf("Read: %s", msg);
            exit(1);
        } else {
            // p1
            dup2(pipe1[1], STDOUT_FILENO);
            puts("Hello");
        }
        wait(NULL);
    }

    return 0;
}