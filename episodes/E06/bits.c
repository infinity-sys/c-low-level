#include <stdio.h>

static void bin8(const char *s, unsigned v)
{
    printf("%-14s", s);
    for (int i = 7; i >= 0; i--)
        putchar(v >> i & 1 ? '1' : '0');
    putchar('\n');
}

int main(void)
{
    unsigned v = 0x29;               /* 0010 1001 */
    bin8("v", v);
    bin8("1u << 4", 1u << 4);
    bin8("set bit 4", v | 1u << 4);
    bin8("clear bit 0", v & ~1u);
    bin8("toggle bit 7", v ^ 1u << 7);
    printf("bit 3 is %u\n", v >> 3 & 1);
    return 0;
}
