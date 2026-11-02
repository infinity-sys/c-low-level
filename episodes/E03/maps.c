#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p = malloc(16);
    char line[256];
    FILE *f = fopen("/proc/self/maps", "r");

    printf("heap %p  stack %p\n", (void *)p, (void *)line);
    while (fgets(line, sizeof line, f))
        fputs(line, stdout);
    fclose(f);
    free(p);
    return 0;
}
