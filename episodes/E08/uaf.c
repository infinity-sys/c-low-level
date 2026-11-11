#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *p = malloc(8);
    if (!p)
        return 1;
    strcpy(p, "hello");
    free(p);
    /* p is no longer ours */
    printf("p = %s\n", p);
    return 0;
}
