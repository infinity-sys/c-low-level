#include <stdio.h>

int pop_loop(unsigned v)
{
    int n = 0;
    while (v) {
        v &= v - 1;      /* clear the lowest 1 bit */
        n++;
    }
    return n;
}

int pop_builtin(unsigned v)
{
    return __builtin_popcount(v);
}

int main(void)
{
    unsigned t[] = {0, 1, 0x29, 0xFF, 0xFFFFFFFF};
    for (int i = 0; i < 5; i++)
        printf("0x%08X: loop %2d builtin %2d\n", t[i],
               pop_loop(t[i]), pop_builtin(t[i]));
    return 0;
}
