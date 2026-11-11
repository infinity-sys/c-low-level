#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *p = malloc(64);
    if (!p)
        return 1;
    strcpy(p, "never freed");
    /* forgot free(p) */
    return 0;
}
