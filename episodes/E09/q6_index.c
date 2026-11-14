#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    printf("a[3]     = %d\n", a[3]);
    printf("*(a + 3) = %d\n", *(a + 3));
    printf("3[a]     = %d\n", 3[a]);
    return 0;
}
