#include <stdio.h>

/* Your turn: rewrite this without any loop */
int is_power_of_two(unsigned v)
{
    if (v == 0)
        return 0;
    while (v % 2 == 0)
        v /= 2;
    return v == 1;
}

int main(void)
{
    unsigned t[] = {0, 1, 2, 3, 64, 96, 1024};
    for (int i = 0; i < 7; i++)
        printf("%4u -> %d\n", t[i], is_power_of_two(t[i]));
    return 0;
}
