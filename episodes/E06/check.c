#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t x = 0x11223344;
    unsigned char *p = (unsigned char *)&x;
    printf("q1: p[0] = 0x%02X\n", p[0]);
    printf("q2: 0xF0 & 0x3C = 0x%02X\n", 0xF0 & 0x3C);
    return 0;
}
