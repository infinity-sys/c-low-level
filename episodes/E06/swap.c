#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t swap32(uint32_t v)
{
    return (v >> 24)
         | ((v >> 8) & 0x0000FF00u)
         | ((v << 8) & 0x00FF0000u)
         | (v << 24);
}

int main(void)
{
    uint32_t x = 0x0A0B0C0D;
    printf("x           = 0x%08X\n", x);
    printf("swap32(x)   = 0x%08X\n", swap32(x));
    printf("bswap32(x)  = 0x%08X\n", __builtin_bswap32(x));
    printf("htonl(x)    = 0x%08X\n", htonl(x));
    printf("ntohl(htonl)= 0x%08X\n", ntohl(htonl(x)));
    return 0;
}
