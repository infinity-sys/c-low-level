#include <stdio.h>

struct t {
    int  n;
    char c;
};

int main(void)
{
    struct t arr[2];

    printf("sizeof = %zu\n", sizeof(struct t));
    printf("arr[0] %p\n", (void *)&arr[0]);
    printf("arr[1] %p\n", (void *)&arr[1]);
    return 0;
}
