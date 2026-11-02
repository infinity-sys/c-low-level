#include <stdio.h>

#define SHOW(T) \
    printf("%-8s %4zu %5zu\n", #T, sizeof(T), _Alignof(T))

int main(void)
{
    printf("type     size align\n");
    SHOW(char);
    SHOW(short);
    SHOW(int);
    SHOW(long);
    SHOW(double);
    SHOW(void *);
    return 0;
}
