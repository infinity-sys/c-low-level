#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t x = 0x0A0B0C0D;
    unsigned char *p = (unsigned char *)&x;

    printf("x = 0x%08X\n", x);
    for (int i = 0; i < 4; i++)
        printf("byte %d at %p: %02X\n",
               i, (void *)(p + i), p[i]);
    return 0;
}
