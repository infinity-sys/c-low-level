#include <stdio.h>
#include <limits.h>

int f(void) { puts("f runs"); return 1; }
int g(void) { puts("g runs"); return 2; }

int main(int argc, char **argv)
{
    (void)argv;
    int a[4] = {0};
    int i = 3 + argc;               // 4: one past the end
    a[i] = 1;                       // 1) out of bounds
    int m = INT_MAX;
    printf("2) %d\n", m + argc);    // INT_MAX + 1
    unsigned u = UINT_MAX;
    printf("3) %u\n", u + 1u);      // UINT_MAX + 1u
    printf("4) %d\n", f() + g());   // who runs first?
    printf("5) %d\n", -1 >> 1);     // negative >> 1
    printf("6) %zu\n", sizeof(long));
    return a[0];
}
