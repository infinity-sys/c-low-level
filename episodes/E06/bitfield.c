#include <stdio.h>
#include <string.h>

struct flags {
    unsigned ready : 1;
    unsigned mode  : 3;
    unsigned level : 4;
};

int main(void)
{
    struct flags f = {0};
    f.ready = 1;
    f.mode  = 5;      /* 101 */
    f.level = 9;      /* 1001 */

    unsigned char b[sizeof f];
    memcpy(b, &f, sizeof f);
    printf("sizeof = %zu\n", sizeof f);
    printf("byte 0 = 0x%02X\n", b[0]);
    f.mode = 9;       /* too big for 3 bits */
    printf("mode   = %u\n", f.mode);
    return 0;
}
