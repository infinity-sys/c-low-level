#include <stdio.h>

struct q1 { char a; char b; int c; };
struct q2 { double d; char c; };

int main(void)
{
    printf("q1: %zu\n", sizeof(struct q1));
    printf("q2: %zu\n", sizeof(struct q2));
    return 0;
}
