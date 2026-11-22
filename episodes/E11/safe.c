#include <stdio.h>
#include <stdckdint.h>
#include <limits.h>

// true when i < u, for every int and unsigned value
static int less(int i, unsigned u)
{
    return i < 0 || (unsigned)i < u;
}

int main(void)
{
    printf("less(-1, 1u) = %d\n", less(-1, 1u));
    int r;
    if (ckd_add(&r, INT_MAX, 1))
        puts("ckd_add: overflow, r not usable");
    if (!ckd_mul(&r, 1000, 1000))
        printf("ckd_mul: r = %d\n", r);
    return 0;
}
