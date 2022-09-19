#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    File *ptr;
    ptr = fopen("02.dat", "a+");

    if (ptr == NULL) {
        printf("Error!");   
        exit(1);
    }

    int *pid = fork()
    if (pid < 0) {
        // a fail fork

    } else if (pid == 0) {
        // child process
        if (ptr == NULL) {
            printf("Child No access!");   
            exit(1);
        }
        fprintf(ptr, "child writes");
    } else {
        // parent process
        if (ptr == NULL) {
            printf("Parent No access!");   
            exit(1);
        }
        fprintf(ptr, "parent writes");
    }

    return 0;
}