#include <stdio.h>
#include <stddef.h>
struct bad {
    char   a;
    double b;
    char   c;
    int    d;
};
struct good {
    double b;
    int    d;
    char   a;
    char   c;
};
#define OFF(S, f) offsetof(struct S, f)
int main(void)
{
    printf("bad:  a %zu b %zu c %zu d %zu size %zu\n",
           OFF(bad, a), OFF(bad, b), OFF(bad, c),
           OFF(bad, d), sizeof(struct bad));
    printf("good: b %zu d %zu a %zu c %zu size %zu\n",
           OFF(good, b), OFF(good, d), OFF(good, a),
           OFF(good, c), sizeof(struct good));
    struct bad x = {0}; struct good y = {0};
    return x.a + y.a;
}
