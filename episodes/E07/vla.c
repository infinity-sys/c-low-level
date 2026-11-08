#include <stdio.h>
#include <stdlib.h>

void fill(size_t n)
{
    char buf[n];        /* VLA: size known at run time */
    for (size_t i = 0; i < n; i++)
        buf[i] = 1;
    printf("filled %zu bytes on the stack\n", n);
}

int main(int argc, char **argv)
{
    fill(strtoul(argv[1], NULL, 10));
    return 0;
}
