/* use int for process time
 * how many days the time overflow
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    printf("process time overflow days: %d\n", INT_MAX/(24*3600*100));

    exit(0);
}
