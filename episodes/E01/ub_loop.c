#include <stdio.h>

int main(void)
{
    long count = 0;
    /* i starts near INT_MAX: i++ overflows */
    for (int i = 2147483600; i > 0; i++)
        count++;
    printf("count = %ld\n", count);
    return 0;
}
