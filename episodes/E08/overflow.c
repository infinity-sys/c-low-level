#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[8];
    /* 16 chars plus the terminating 0: writes past buf */
    strcpy(buf, "this is too long");
    printf("buf = %s\n", buf);
    return 0;
}
