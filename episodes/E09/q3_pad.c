#include <stdio.h>
#include <stddef.h>

struct A { char c; int i; char d; };
struct B { int i; char c; char d; };

int main(void)
{
    printf("sizeof(struct A) = %zu\n", sizeof(struct A));
    printf("  offsets c=%zu i=%zu d=%zu\n",
           offsetof(struct A, c), offsetof(struct A, i),
           offsetof(struct A, d));
    printf("sizeof(struct B) = %zu\n", sizeof(struct B));
    printf("  offsets i=%zu c=%zu d=%zu\n",
           offsetof(struct B, i), offsetof(struct B, c),
           offsetof(struct B, d));
    return 0;
}
