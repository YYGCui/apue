#include "apue.h"
#include <errno.h>

int main(void)
{
    off_t currpos;
    errno = 0;
    if ((currpos = lseek(STDIN_FILENO, 0, SEEK_CUR)) == -1)
    {
        perror("cannot seek");
    }
    else
    printf("seek OK: offset = %ld\n", currpos);

    exit(0);
}
