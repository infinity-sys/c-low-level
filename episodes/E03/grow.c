#include <stdio.h>
#include <stdlib.h>

void dive(int depth)
{
    int here = depth;
    printf("depth %d  %p\n", depth, (void *)&here);
    if (depth < 3)
        dive(depth + 1);
}

int main(void)
{
    dive(0);
    char *a = malloc(16);
    char *b = malloc(16);
    char *c = malloc(16);
    char *big = malloc(1 << 20);
    printf("a    %p\n", (void *)a);
    printf("b    %p\n", (void *)b);
    printf("c    %p\n", (void *)c);
    printf("big  %p\n", (void *)big);
    free(a); free(b); free(c); free(big);
    return 0;
}
