#include <stdio.h>

int main(void)
{
    int x;          /* never set */
    if (x)
        printf("x is not zero: %d\n", x);
    else
        printf("x is zero\n");
    return 0;
}
