#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#ifdef FIXED
volatile sig_atomic_t done;   /* the right type */
#else
int done;                     /* a plain int */
#endif

void on_alarm(int sig) {
    (void)sig;
    done = 1;
}

int main(void) {
    signal(SIGALRM, on_alarm);
    alarm(1);                 /* SIGALRM in 1 second */
    while (!done) { }         /* wait for the handler */
    puts("done");
    return 0;
}
