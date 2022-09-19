#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    FILE *ptr = NULL;
    ptr = fopen("02.dat", "a+");

    if (ptr == NULL) {
        printf("Error!");   
        exit(1);
    }

    int pid = fork();
    int *re = NULL;
    if (pid < 0) {
        // a fail fork
        exit(1);
    } else if (pid == 0) {
        // child process
        if (ptr == NULL) {
            printf("Child No access!");   
            exit(1);
        }
        fprintf(ptr, "child writes\n");
    } else {
        // parent process
        if (ptr == NULL) {
            printf("Parent No access!");   
            exit(1);
        }
        fprintf(ptr, "parent writes\n");
        wait(re);
    }

    return 0;
}