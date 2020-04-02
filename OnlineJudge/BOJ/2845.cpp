#include <stdio.h>

int main() {
    int sum = 0, i;
    int x, y;

    scanf("%d %d", &x, &y);
    sum = x*y;

    for(i=1 ; i<=5 ; i++) scanf("%d", &x), printf("%d ", x-sum);
}