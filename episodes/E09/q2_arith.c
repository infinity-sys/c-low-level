#include <stdio.h>

struct rec { int id; short x; short y; int z; };

int main(void)
{
    char   c[4];
    int    i[4];
    double d[4];
    struct rec r[4];
    printf("char   +3: %td bytes\n",
           (char *)(c + 3) - (char *)c);
    printf("int    +3: %td bytes\n",
           (char *)(i + 3) - (char *)i);
    printf("double +3: %td bytes\n",
           (char *)(d + 3) - (char *)d);
    printf("rec    +3: %td bytes\n",
           (char *)(r + 3) - (char *)r);
    printf("sizeof(struct rec) = %zu\n", sizeof r[0]);
    return 0;
}
