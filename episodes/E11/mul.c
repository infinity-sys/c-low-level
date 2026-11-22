#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t a = 65535, b = 65535;
    uint32_t bad = a * b;           // int * int: overflow!
    uint32_t good = (uint32_t)a * b;
    printf("bad  = %u\n", bad);
    printf("good = %u\n", good);
    return 0;
}
