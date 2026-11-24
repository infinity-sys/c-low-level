#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t bits_cast(float f) {
    return *(uint32_t *)&f;
}

uint32_t bits_memcpy(float f) {
    uint32_t u;
    memcpy(&u, &f, sizeof u);
    return u;
}

uint32_t bits_union(float f) {
    union { float f; uint32_t u; } p = { .f = f };
    return p.u;
}

int main(void) {
    printf("cast   0x%08x\n", bits_cast(1.0f));
    printf("memcpy 0x%08x\n", bits_memcpy(1.0f));
    printf("union  0x%08x\n", bits_union(1.0f));
    return 0;
}
