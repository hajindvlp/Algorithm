#include <stdio.h>

int main() {
    int x, sum = 0, i;

    for(i=1 ; i<=5 ; i++) scanf("%d", &x), sum+=x*x;

    printf("%d", sum%10);
}