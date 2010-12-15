#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#ifndef MAXLINE
#define MAXLINE 4096
#endif

int
main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");

    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace EOL */

        if((pid = fork()) < 0) {
            printf("%s\n", strerror(errno));
        } else if(pid == 0) { /* child process */
            execlp(buf, buf, (char *)0);
            printf("%s\n", strerror(errno));
            exit(127);
        }

        /* parent process */
        if((pid = waitpid(pid, &status, 0)) < 0)
            printf("%s\n", strerror(errno));
            
        printf("%% ");
    }
}

