#include <stdio.h>

void show(int a[10])
{
    printf("in show: sizeof a = %zu\n", sizeof a);
}

int main(void)
{
    int arr[10] = {10, 11, 12, 13};

    printf("in main: sizeof arr = %zu\n", sizeof arr);
    show(arr);
    printf("arr      %p\n", (void *)arr);
    printf("&arr     %p\n", (void *)&arr);
    printf("arr + 1  %p\n", (void *)(arr + 1));
    printf("&arr + 1 %p\n", (void *)(&arr + 1));
    printf("arr[2] %d  *(arr + 2) %d  2[arr] %d\n",
           arr[2], *(arr + 2), 2[arr]);
    return 0;
}
