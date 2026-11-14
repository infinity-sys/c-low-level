#include <stdio.h>

void f(int a[10])
{
    printf("in f:    sizeof a = %zu\n", sizeof a);
}

int main(void)
{
    int a[10];
    printf("in main: sizeof a = %zu\n", sizeof a);
    f(a);
    return 0;
}
