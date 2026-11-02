#include <stdlib.h>

int a = 5;
int b;
static int c = 0;
const char d[] = "ro";
char *e = "lit";

int main(void)
{
    static int f = 1;
    int g = 2;
    int *h = malloc(4);
    free(h);
    return a + b + c + f + g + d[0] + e[0];
}
