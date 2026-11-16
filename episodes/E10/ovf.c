#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int will_overflow(int x)
{
    return x + 1 < x;   // is x + 1 smaller than x?
}

int main(int argc, char **argv)
{
    int x = argc > 1 ? atoi(argv[1]) : INT_MAX;
    printf("x = %d\n", x);
    printf("will_overflow(x) = %d\n", will_overflow(x));
    return 0;
}
