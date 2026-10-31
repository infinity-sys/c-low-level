#include <stdio.h>

int main(void)
{
    printf("char        %zu\n", sizeof(char));
    printf("short       %zu\n", sizeof(short));
    printf("int         %zu\n", sizeof(int));
    printf("long        %zu\n", sizeof(long));
    printf("void *      %zu\n", sizeof(void *));
    printf("long double %zu\n", sizeof(long double));
    return 0;
}
