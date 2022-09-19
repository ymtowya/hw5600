#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>

int main() {
    const int loops  = 10;

    int myFile = open("./test.dat", O_CREAT | O_RDONLY);
    if (myFile == -1) {
        exit(1);
    }

    struct timeval start, end;
    char msg[128];

    for (int i = 0; i < loops; ++i) {
        gettimeofday(&start, NULL);
        read(myFile, msg, 0);
        gettimeofday(&end, NULL);
        printf("Start: %d - End: %d\nDuration: %d\n", start.tv_usec, end.tv_usec, end.tv_usec - start.tv_usec);
    }
    
    close(myFile);

    return 0;
}