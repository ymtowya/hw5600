#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x;
    // access
    x = 100;
    int rc = fork();
    int *re = NULL;
    if (rc < 0) {
        // Fork did not success
        fprintf(stderr, "Fork did not success.\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        printf("x in the child process -init: %d\n", x);
        // change
        x = 99;
        printf("x in the child process -after: %d\n", x);
    } else {
        printf("x in the parent process -init: %d\n", x);
        // change
        x = 101;
        printf("x in the parent process -after: %d\n", x);
        wait(re);
    }
    return 0;
}