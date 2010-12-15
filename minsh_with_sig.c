#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#ifndef MAXLINE
#define MAXLINE 4096
#endif

static void sig_int(int); /* signal catching function */

int
main(int argc, char *argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR)
        perror(argv[0]);

    printf("%% ");

    while(fgets(buf, MAXLINE, stdin) != NULL) {
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace EOL */

        if(strlen(buf) == 0) {
            printf("%% ");
            continue;
        }

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

void
sig_int(int signo)
{
    printf("Interrupted\n%%");
}
