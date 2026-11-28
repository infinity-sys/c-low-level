#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint64_t get_bits_cast(double d) { return *(uint64_t *)&d; }

uint64_t get_bits(double d) {
    uint64_t u;
    memcpy(&u, &d, sizeof u);
    return u;
}

uint16_t read_u16_cast(const unsigned char *p) {
    return *(uint16_t *)(p + 1);
}

uint16_t read_u16(const unsigned char *p) {
    uint16_t v;
    memcpy(&v, p + 1, sizeof v);
    return v;
}

int main(void) {
    _Alignas(4) unsigned char b[4] =
        {0x11, 0x22, 0x33, 0x44};
    printf("cast   %#llx %#x\n",
           (unsigned long long)get_bits_cast(1.0),
           read_u16_cast(b));
    printf("memcpy %#llx %#x\n",
           (unsigned long long)get_bits(1.0), read_u16(b));
    return 0;
}
