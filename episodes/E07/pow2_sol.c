#include <stdio.h>

/* E06 answer: no loop, one line */
int is_power_of_two(unsigned v)
{
    return v != 0 && (v & (v - 1)) == 0;
}

int main(void)
{
    unsigned t[] = {0, 1, 2, 3, 64, 96, 1024};
    for (int i = 0; i < 7; i++)
        printf("%4u -> %d\n", t[i], is_power_of_two(t[i]));
    printf("0 & (0 - 1) = %u\n", 0u & (0u - 1));
    return 0;
}
