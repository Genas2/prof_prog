#include <stdio.h>
#include <stdlib.h>

#include <unistd.h> /* gituid() and getgid() */

int
main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
