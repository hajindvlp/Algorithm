#include <stdio.h>

int main() {
    int x1, x2, x3;
    int y1, y2, y3;
    int x, y;

    scanf("%d", &x);
    x1 = x%10, x/=10;
    x2 = x%10, x/=10;
    x3 = x%10, x/=10;

    scanf("%d", &x);
    y1 = x%10, x/=10;
    y2 = x%10, x/=10;
    y3 = x%10, x/=10;

    x = x1*100 + x2*10 + x3;
    y = y1*100 + y2*10 + y3;

    printf("%d", (x>y) ? x:y);
}