#include <stdio.h>
#include <limits.h>

int f(void) { puts("f runs"); return 1; }
int g(void) { puts("g runs"); return 2; }

int main(void)
{
    int s = f() + g();       // unspecified order
    printf("s = %d\n", s);
    printf("-7 >> 1 = %d\n", -7 >> 1);
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("char is %s\n",
           CHAR_MIN < 0 ? "signed" : "unsigned");
    return 0;
}
