#include <stdio.h>

int main(void)
{
    unsigned int x = 0x11223344;
    unsigned char *b = (unsigned char *)&x;
    printf("x = 0x%08x\n", x);
    printf("bytes: %02x %02x %02x %02x\n",
           b[0], b[1], b[2], b[3]);
    return 0;
}
