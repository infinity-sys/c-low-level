#include <stdio.h>
#include <time.h>

void delay(void) {
    for (int i = 0; i < 100000000; i++) { }
}

void delay_v(void) {
    for (volatile int i = 0; i < 100000000; i++) { }
}

double secs(void (*f)(void)) {
    clock_t t0 = clock();
    f();
    return (double)(clock() - t0) / CLOCKS_PER_SEC;
}

int main(void) {
    printf("delay   %.3f s\n", secs(delay));
    printf("delay_v %.3f s\n", secs(delay_v));
    return 0;
}
