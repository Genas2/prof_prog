#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int val;
    
    if(argc != 2)
        err_quit("Usage: %s <descriptor number>", argv[0]);

    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
        err_sys("%s: fcntl error for %d file descriptor", argv[0], atoi(argv[1]));

    switch(val & O_ACCMODE) {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read and write");
        break;
    default:
        err_dump("unknown access mode");
    }

    if(val & O_APPEND)
        printf(", appending");
    if(val & O_NONBLOCK)
        printf(", non-block mode");
    
#if defined(O_SYNC)
    if(val & O_SYNC)
        printf(", syncronous write");
#endif
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
    if(val & O_FSYNC)
        printf(", syncronous write"); 
#endif

    putchar('\n');
    
    exit(0);
}
