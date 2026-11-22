#include <stdio.h>

int main(void)
{
    unsigned char a = 200, b = 100;
    printf("a + b = %d\n", a + b);
    printf("sizeof(a + b) = %zu\n", sizeof(a + b));
    unsigned char c = a + b;        // back to 8 bits
    printf("c = %d\n", c);
    unsigned short x = 65535;
    printf("x + 1 = %d\n", x + 1);
    char ch = 'A';
    printf("sizeof(ch + 0) = %zu\n", sizeof(ch + 0));
    return 0;
}
