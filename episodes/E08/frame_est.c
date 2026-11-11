#include <stdio.h>

/* Your turn: estimate the frame size of work() */
void work(int n)
{
    int a[100];
    double d = n * 0.5;
    char name[20];
    a[0] = n;
    name[0] = 'A';
    printf("%d %.1f %c\n", a[0], d, name[0]);
}

int main(void)
{
    work(7);
    return 0;
}
