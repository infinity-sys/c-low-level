#include <stdio.h>
#include <stdint.h>

static int is_little(void)
{
    uint16_t one = 1;
    unsigned char first = *(unsigned char *)&one;
    return first == 1;
}

int main(void)
{
    printf("runtime: %s endian\n",
           is_little() ? "little" : "big");
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    printf("compile time: little endian\n");
#else
    printf("compile time: big endian\n");
#endif
    return 0;
}
