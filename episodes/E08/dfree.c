#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *p = malloc(8);
    if (!p)
        return 1;
    strcpy(p, "hello");
    free(p);
    free(p);   /* already freed */
    return 0;
}
