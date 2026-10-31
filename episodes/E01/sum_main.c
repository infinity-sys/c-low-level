#include <stdio.h>

int sum_to(int n);

int main(void)
{
    printf("sum_to(5)     = %d\n", sum_to(5));
    printf("sum_to(65535) = %d\n", sum_to(65535));
    return 0;
}
