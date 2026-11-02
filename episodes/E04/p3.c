#include <stdio.h>

struct rec {
    int    id;
    char   tag;
    double score;
};

int main(void)
{
    char       c[4];
    int        i[4];
    struct rec r[4];
    char       *pc = c;
    int        *pi = i;
    struct rec *pr = r;

    /* Predict the bytes each p + 3 moves, then check:
    printf("%td\n", (char *)(pc + 3) - (char *)pc);
    printf("%td\n", (char *)(pi + 3) - (char *)pi);
    printf("%td\n", (char *)(pr + 3) - (char *)pr);
    */
    (void)pc; (void)pi; (void)pr;
    return 0;
}
