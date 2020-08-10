#include <stdio.h>

int main() {
    int a, x, i, cnt = 0;

    scanf("%d", &a);
    for(i=1 ; i<=5 ; i++) scanf("%d", &x), (x==a)?cnt++:0;
    printf("%d", cnt);
}