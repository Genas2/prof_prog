#include <stdlib.h>      // exit()
#include <unistd.h>      // STDIN_FILENO and STDOUT_FILENO
#include <stdio.h>       // printf()
#include <errno.h>       // errno
#include <string.h>      // strerror()

#define BUFFSIZE 4

int main(void) {
    int n;
    char buf[BUFFSIZE];

    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0 )
        if(write(STDOUT_FILENO, buf, n) != n)
            printf("%s\n", strerror(errno));

    if(n < 0)
        printf("%s\n", strerror(errno));

    exit(0);
}
