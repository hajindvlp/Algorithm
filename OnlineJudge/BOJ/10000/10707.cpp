#include <stdio.h>

int main() {
    int a, b, c, d, e;
    int x1, x2;

    scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
    x1 = e*a;
    x2 = b + ((e>c)?(e-c)*d:0);
    printf("%d", (x1<x2)?x1:x2);
}