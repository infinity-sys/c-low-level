#include <stdio.h>

int first(int *p)
{
    int v = *p;         // read through p
    if (p == NULL)      // checked too late
        return -1;
    return v;
}

int main(void)
{
    int a = 7;
    printf("first(&a) = %d\n", first(&a));
    return 0;
}
