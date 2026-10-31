#include <stdio.h>

int checksum(const char *s);   /* declared only */

int main(void)
{
    printf("%d\n", checksum("abc"));
    return 0;
}
