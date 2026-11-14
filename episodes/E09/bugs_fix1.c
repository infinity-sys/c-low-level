#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exercise for episode 9.
   This file has three memory bugs.
   Find them with AddressSanitizer and
   Valgrind. Do not fix them yet. */

void greet(void)
{
    char buf[16];  /* bug 1 fixed */
    char *p = malloc(16);
    int n;

    if (!p)
        return;
    strcpy(p, "hello, world");
    strcpy(buf, p);
    printf("buf = %s\n", buf);
    free(p);
    printf("p = %s\n", p);
    if (n)
        printf("n = %d\n", n);
}

int main(void)
{
    greet();
    return 0;
}
