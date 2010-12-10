//#include "apue.2e/include/apue.h"
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    char *dirname = malloc(sizeof(argv[1]));
    struct dirent *dirp;
    int i;

    if(argc != 2) {
        strcpy(dirname, ".");
    }
    else
        strcpy(dirname, argv[1]);

    if((dp = opendir(dirname)) == NULL) {
        printf("%s\n", strerror(errno)); //No such file or directory
        exit(errno);
    }

    while((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
    exit(0);
}
