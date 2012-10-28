#include "apue.h"
#include <time.h>
#include <sys/time.h>

int main()
{
    time_t *ttp;
    struct tm *tmp;
    char buf[1024];
    int ms=1024;

    if (time(ttp) != -1)
    if((tmp=localtime(ttp)) != NULL)
    if(strftime(buf, ms, "%a %b %d %T %Z %Y", tmp) != 0)
    printf("%s\n", buf);
}
