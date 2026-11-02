#include <stdio.h>

int main(void)
{
    short s[8];
    char *c = "x";
    double *d = 0;

    printf("short: %td bytes\n", (char *)(s + 5) - (char *)s);
    printf("sizeof c %zu, sizeof d %zu\n", sizeof c, sizeof d);
    (void)d;
    return 0;
}
