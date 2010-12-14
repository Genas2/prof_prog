#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main(void)
{
    printf("My PID is %d\n", getpid());
    exit(0);
}
