#include <stdio.h>

int same(int *a, int *b);

int main(void)
{
    int x = 0;

    printf("same(&x, &x) = %d\n", same(&x, &x));
    return 0;
}
