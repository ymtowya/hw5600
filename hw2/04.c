#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int i = 0;
    char *lsArgv[3];
    lsArgv[0] = strdup("ls");
    lsArgv[1] = strdup("/");
    lsArgv[2] = NULL;

    for (; i < 5; ++i) {
        int childPid = fork();
        if (childPid < 0) {
            exit(1);
        } else if (childPid == 0) {
            // child
            switch (i)
            {
            case 0:
                execl("/bin/ls", "ls", "/", NULL);
                break;
            case 1:
                execle("/bin/ls", "ls", "/", NULL);
                break;
            case 2:
                execlp("/bin/ls", "/bin/ls", "/", NULL);
                break;
            case 3:
                execv("/bin/ls", lsArgv);
            default:
                break;
            }
            
            exit(1);
        } else {
            // parent
            wait(NULL);
        } 
    }

    return 0;
}