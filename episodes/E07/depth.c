#include <stdio.h>

static long depth;

void dive(void)
{
    char pad[1024];           /* 1 KB in every frame */
    depth++;
    if (depth <= 2)
        fprintf(stderr, "%ld: %p\n", depth, (void *)pad);
    if (depth % 1000 == 0)
        fprintf(stderr, "depth %ld\n", depth);
    dive();
    pad[0] = 0;               /* work after the call */
}

int main(void)
{
    dive();
    return 0;
}
