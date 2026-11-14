#include <stdio.h>

int *make(void)
{
    int n = 42;
    return &n;
}

int main(void)
{
    int *p = make();
    printf("p = %p\n", (void *)p);
    fflush(stdout);
    printf("*p = %d\n", *p);
    return 0;
}
