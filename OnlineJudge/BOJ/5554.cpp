#include <stdio.h>

int main() {
    int x, sum = 0, i;

    for(i=1 ; i<=4 ; i++) scanf("%d", &x), sum+=x;

    printf("%d\n%d", sum/60, sum%60);
}