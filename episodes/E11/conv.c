#include <stdio.h>

unsigned char low_byte(int n)  { return n; }
unsigned to_unsigned(int i)    { return i; }
int sum(unsigned char a, unsigned char b)
{
    unsigned char c = a + b;
    return c;
}

int main(void)
{
    printf("low_byte(300)   = %d\n", low_byte(300));
    printf("to_unsigned(-1) = %u\n", to_unsigned(-1));
    printf("sum(200, 100)   = %d\n", sum(200, 100));
    return 0;
}
