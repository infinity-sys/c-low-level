#include <stdio.h>

struct point { int x, y, z; };

int main(void)
{
    char   c[4];
    int    i[4];
    double d[4];
    struct point s[4];

    printf("char   %p %p\n", (void *)c, (void *)(c + 1));
    printf("int    %p %p\n", (void *)i, (void *)(i + 1));
    printf("double %p %p\n", (void *)d, (void *)(d + 1));
    printf("point  %p %p\n", (void *)s, (void *)(s + 1));
    printf("(i + 3) - i = %td\n", (i + 3) - i);
    printf("in bytes    = %td\n",
           (char *)(i + 3) - (char *)i);
    return 0;
}
