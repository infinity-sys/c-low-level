#include <stdio.h>

int main(void)
{
    int a[3] = {10, 20, 30};
    int *p = a;
    int x = *p++;
    printf("x = %d, *p = %d\n", x, *p);
    (*p)++;
    printf("a = {%d, %d, %d}\n", a[0], a[1], a[2]);
    int y = ++*p;
    printf("y = %d, p - a = %td\n", y, p - a);
    return 0;
}
