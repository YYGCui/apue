#include "apue.h"
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int srcfd, desfd;
    int i = 0;
    int srcval, desval;
    int *dupfd;

    if (argc != 3)
    err_quit("Usage: a.out <sourcefd> <desfd>");

    srcfd = atoi(argv[1]);
    desfd = atoi(argv[2]);

    close(desfd);
    
    dupfd = (int *)malloc(sizeof(int)*desfd);

    while ((dupfd[i] = dup(srcfd)) != desfd)
    {
        if (dupfd[i] == -1)
        err_sys("dup error");
        
        i++;
    }

    if ((srcval = fcntl(srcfd, F_GETFD, 0)) < 0)
    err_sys("error to get FD, fd=%d\n", srcfd);

    printf("source fd = %d, FD = %d\n", srcfd, srcval);

    if ((desval = fcntl(dupfd[i], F_GETFD, 0)) < 0)
    err_sys("error to get FD, fd=%d\n", dupfd[i]);

    printf("des fd = %d, FD = %d\n", dupfd[i], desval);

    while (--i != -1)
    close(dupfd[i]);

    free(dupfd);

    exit(0);
}
