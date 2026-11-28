#include <pthread.h>
#include <stdio.h>

volatile int v;               /* volatile: not atomic */
_Atomic int a;                /* C11 atomic */

void *work(void *arg) {
    (void)arg;
    for (int i = 0; i < 1000000; i++) {
        v++;
        a++;
    }
    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, work, NULL);
    pthread_create(&t2, NULL, work, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("volatile %d\n", v);
    printf("atomic   %d\n", a);
    return 0;
}
