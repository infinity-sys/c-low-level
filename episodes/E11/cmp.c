#include <stdio.h>

int main(void)
{
    int i = -1;
    unsigned u = 1;
    printf("i < u   : %d\n", i < u);
    printf("(unsigned)i = %u\n", (unsigned)i);
    long l = -1;
    printf("l < u   : %d\n", l < u);
    printf("i < sizeof(int) : %d\n", i < sizeof(int));
    printf("-1 < 1u : %d\n", -1 < 1u);
    return 0;
}
