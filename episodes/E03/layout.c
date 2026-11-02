#include <stdio.h>
#include <stdlib.h>

int counter = 7;
int zeroed;
const int limit = 100;
static int calls;

int main(void)
{
    int local = 1;
    static int seen = 3;
    const char *msg = "hello";
    int *heap = malloc(sizeof *heap);
    printf("main     %p\n", (void *)main);
    printf("limit    %p\n", (void *)&limit);
    printf("msg      %p\n", (void *)msg);
    printf("counter  %p\n", (void *)&counter);
    printf("seen     %p\n", (void *)&seen);
    printf("zeroed   %p\n", (void *)&zeroed);
    printf("calls    %p\n", (void *)&calls);
    printf("heap     %p\n", (void *)heap);
    printf("local    %p\n", (void *)&local);
    free(heap);
    return 0;
}
