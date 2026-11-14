#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "hello";
    char a[] = "hello";
    printf("sizeof s = %zu, sizeof a = %zu\n",
           sizeof s, sizeof a);
    printf("strlen s = %zu, strlen a = %zu\n",
           strlen(s), strlen(a));
    a[0] = 'H';
    printf("a = %s\n", a);
    fflush(stdout);
    s[0] = 'H';          /* a string literal */
    printf("s = %s\n", s);
    return 0;
}
