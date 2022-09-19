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
    char *hello = ":Hello\n";
    
    if (childPid1 < 0) {
        exit(1);
    } else if (childPid1 == 0) {
        printf("child 1\n");
    } else {
        childPid2 = fork();
        if (childPid2 < 0) {
            exit(1);
        } else if (childPid2 == 0) {
            // p2
            printf("child 2\n");
            printf("Output: %s\n", hello);
            write(fds[1], hello, msg_size);
            exit(1);
        } else {
            // p1
            wait(NULL);
            if (read(fds[0], msg, msg_size) > 0) {
                printf("Read: %s\n", msg);
            }
            exit(1);
        }
        wait(NULL);
    }

    return 0;
}