#include <stdio.h>

struct six {
    char   flag;
    double value;
    short  port;
    int    count;
    char   kind;
    long   id;
};

int main(void)
{
    printf("sizeof = %zu\n", sizeof(struct six));
    return 0;
}
