#include <stdio.h>
struct Q { char a; double b; char c; };
int main(void)
{
    short s[5];
    unsigned int x = 0x01020304;
    printf("sizeof(struct Q) = %zu\n", sizeof(struct Q));
    printf("&s[4] - &s[0] = %td\n", &s[4] - &s[0]);
    printf("bytes apart = %td\n", (char *)&s[4] - (char *)&s[0]);
    printf("byte[1] of x = 0x%02x\n", ((unsigned char *)&x)[1]);
    return 0;
}
