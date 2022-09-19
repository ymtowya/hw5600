#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    int i = 0;
    char *lsArgv[3];
    lsArgv[0] = strdup("ls");
    lsArgv[1] = strdup("/Users/mtowya/Desktop");
    lsArgv[2] = NULL;

    for (; i < 6; ++i) {
        int childPid = fork();
        if (childPid < 0) {
            exit(1);
        } else if (childPid == 0) {
            // child
            switch (i)
            {
            case 0:
                execl("/bin/ls", "ls", "/Users/mtowya/Desktop", NULL);
                break;
            case 1:
                execlp("/bin/ls", "/bin/ls", "/Users/mtowya/Desktop", NULL);
                break;
            case 2:
                execle("/bin/ls", "ls", "/Users/mtowya/Desktop", NULL);
                break;
            case 3:
                execv("/bin/ls", lsArgv);
                break;
            case 4:
				execvp("ls", lsArgv);
				break;
			case 5:
				execvpe("ls", lsArgv);
				break;
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