#include <stdio.h>

int main(void)
{
    int nums[4] = {1, 2, 255, 256};
    const char *msg = "hi!";
    int *p = nums;

    p = p + 2;
    printf("%d %s\n", *p, msg);
    return 0;
}
