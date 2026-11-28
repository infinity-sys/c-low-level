#include <stdio.h>

const int limit = 10;         /* a const object */

int twice(const int *p, int *q) {
    int a = *p;
    *q = 0;                   /* may change *p */
    return a + *p;
}

int use_limit(void) { return limit * 2; }

#ifdef BAD
void set(const int *p) { *p = 1; }
#endif

int main(void) {
    int x = 5;
    printf("twice(&x, &x) = %d\n", twice(&x, &x));
    printf("use_limit()   = %d\n", use_limit());
    return 0;
}
