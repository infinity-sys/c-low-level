#include <stdio.h>
#define TYPE(x) _Generic((x), int: "int", unsigned: "unsigned int", \
    long: "long", unsigned long: "unsigned long", double: "double")
#define SHOW(e, fmt) printf("%-26s %-14s " fmt "\n", #e, TYPE(e), e)

int main(void) {
    SHOW('A' + 1, "%d");
    SHOW((unsigned char)200 + 100, "%d");
    SHOW(10u - 20, "%u");
    SHOW(-1L < 1u, "%d");
    SHOW(7 / 2 * 2.0, "%.1f");
    SHOW(sizeof('A'), "%zu");
    return 0;
}
