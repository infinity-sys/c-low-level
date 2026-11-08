#include <stdio.h>

void c(void)
{
    int z = 3;
    printf("c:    &z = %p\n", (void *)&z);
}

void b(void)
{
    int y = 2;
    printf("b:    &y = %p\n", (void *)&y);
    c();
}

int main(void)
{
    int x = 1;
    printf("main: &x = %p\n", (void *)&x);
    b();
    return 0;
}
