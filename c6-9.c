#include "apue.h"
#include <sys/utsname.h>
#include <errno.h>

int main()
{
    int i;
    struct utsname *nptr=NULL;
    char *hostname;
    int namelen = 256;

    i = uname(nptr);
    printf("%d\n",i);
    if (i > -1)
    {
        printf("%s \n%s \n%s \n%s \n%s\n", nptr->sysname, nptr->nodename, nptr->release, nptr->version, nptr->machine);
    }
    else
    {
        err_sys("uname error");
        printf("Error: %s\n", strerror(errno));
    }

    if (!gethostname(hostname, namelen))
    {
        printf("HostName: %s\n", hostname);
    }

    return 0;
}
