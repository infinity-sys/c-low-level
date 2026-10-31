#include <stdio.h>

#define SQ(x)  x * x
#define SQP(x) ((x) * (x))

int main(void)
{
    printf("SQ(1 + 2)  = %d\n", SQ(1 + 2));
    printf("SQP(1 + 2) = %d\n", SQP(1 + 2));
    return 0;
}
