#include <stdio.h>

struct six {          /* the exercise: 40 bytes */
    char   flag;
    double value;
    short  port;
    int    count;
    char   kind;
    long   id;
};
struct six_sorted {   /* largest alignment first */
    double value;
    long   id;
    int    count;
    short  port;
    char   flag;
    char   kind;
};

int main(void)
{
    printf("six        = %zu\n", sizeof(struct six));
    printf("six_sorted = %zu\n", sizeof(struct six_sorted));
    return 0;
}
