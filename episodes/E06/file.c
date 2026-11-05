#include <stdio.h>
#include <stdint.h>

static uint32_t read_be32(const unsigned char *b)
{
    return (uint32_t)b[0] << 24 | (uint32_t)b[1] << 16
         | (uint32_t)b[2] << 8  | (uint32_t)b[3];
}

int main(void)
{
    uint32_t x = 0x0A0B0C0D;
    unsigned char be[4] = {0x0A, 0x0B, 0x0C, 0x0D};

    FILE *f = fopen("raw.bin", "wb");
    fwrite(&x, sizeof x, 1, f);       /* host order */
    fclose(f);

    printf("read_be32 = 0x%08X\n", read_be32(be));
    return 0;
}
