#include <stdio.h>

__attribute__((noinline))
int store(int *i, float *f) {
    *i = 1;
    *f = 0.0f;
    return *i;
}

int main(void) {
    int x;
    int r = store(&x, (float *)&x);
    printf("returned %d, x is now %d\n", r, x);
    return 0;
}
