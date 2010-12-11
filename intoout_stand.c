#include <stdlib.h>      // exit()
#include <unistd.h>      // STDIN_FILENO and STDOUT_FILENO
#include <stdio.h>       // printf()
#include <errno.h>       // errno
#include <string.h>      // strerror()

#define BUFFSIZE 4

int main(void) {
    int c;

    while((c = getc(stdin)) != EOF)
        if(putc(c, stdout) == EOF)
            printf("%s\n", strerror(errno));

    if(ferror(stdin))
        printf("%s\n", strerror(errno));

    exit(0);
}
