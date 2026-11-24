#include <stdio.h>
#include <time.h>
#define N 4096
#define REPS 200000
#define SEC(t) ((double)(t) / CLOCKS_PER_SEC)

__attribute__((noinline))
void sum(int *acc, const int *v, int n) {
    for (int i = 0; i < n; i++) *acc += v[i];
}

__attribute__((noinline))
void sum_r(int *restrict acc, const int *restrict v, int n) {
    for (int i = 0; i < n; i++) *acc += v[i];
}

int v[N];

int main(void) {
    for (int i = 0; i < N; i++) v[i] = i & 1;
    int a = 0, b = 0;
    clock_t t0 = clock();
    for (int r = 0; r < REPS; r++) sum(&a, v, N);
    clock_t t1 = clock();
    for (int r = 0; r < REPS; r++) sum_r(&b, v, N);
    clock_t t2 = clock();
    printf("sum   %d  %.3f s\n", a, SEC(t1 - t0));
    printf("sum_r %d  %.3f s\n", b, SEC(t2 - t1));
    return 0;
}
