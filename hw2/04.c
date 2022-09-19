#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

    int i = 0;
    char *addr = "/home/ubuntu/hw";
    char *lsArgv[3];
    lsArgv[0] = strdup("ls");
    lsArgv[1] = strdup(addr);
    lsArgv[2] = NULL;
    char *path = getenv("PATH");
    char  pathenv[strlen(path) + sizeof("PATH=")];
    sprintf(pathenv, "PATH=%s", path);
    char *envp[] = {pathenv, NULL};
    char *tests[] = {"ls", NULL};

    for (; i < 6; ++i) {
        int childPid = fork();
        if (childPid < 0) {
            exit(1);
        } else if (childPid == 0) {
            // child
            switch (i)
            {
            case 0:
                printf("execl:\n");
                execl("/bin/ls", "ls", addr, NULL);
                break;
            case 1:
                printf("execlp:\n");
                execlp("/bin/ls", "/bin/ls", addr, NULL);
                break;
            case 2:
                // Not sure why this cannot be added
                //printf("execle:\n");
                execle("/bin/ls", "ls", addr, NULL);
                break;
            case 3:
                printf("execv:\n");
                execv("/bin/ls", lsArgv);
                break;
            case 4:
                printf("execvp:\n");
				execvp("ls", lsArgv);
				break;
			case 5:
                printf("execvpe:\n");
                execvpe(tests[0], tests, envp);
				// execvpe("ls", lsArgv);
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