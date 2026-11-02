#include <stdio.h>
#include <stddef.h>

struct pk {
    char   a;
    double b;
} __attribute__((packed));

double get(struct pk *p)
{
    return p->b;
}

int main(void)
{
    printf("size %zu, offset of b %zu, align %zu\n",
           sizeof(struct pk), offsetof(struct pk, b),
           _Alignof(struct pk));
    return 0;
}
