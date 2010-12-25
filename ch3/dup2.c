#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#ifndef MAX_LINE
#define MAX_LINE 4096
#endif

int
main(int argc, char *argv[]) {
    int fd;
    int z;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    char buf[MAX_LINE];
    char path[MAX_LINE];


    fd = open("wp.txt", O_RDWR | O_APPEND | O_CREAT, mode); 
    
    //printf("Testing %d\n", fd);

    //if (write(fd, buf, strlen(buf)) == -1)
    //    perror(argv[0]);

    //sprintf(path, "/dev/fd/%d", fd);
    //z = open(path, O_RDWR | O_APPEND | O_CREAT, mode);

    //if (read(z, buf, MAX_LINE) == -1)
    //    perror(argv[0]);

    //close(z);

    ////printf("Testing %d\n", z);
    //read(z, buf, MAX_LINE);
    //printf("%s\n", buf);
    close(fd);
    printf("Testing %d\n", fd);

    exit(0);
}

int
dup2(int newfd, int oldfd) {
    return 0;
}
