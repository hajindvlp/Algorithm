#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x;

    scanf("%d", &n);
    while(n--) {
        scanf("%lf", &x);
        x *= 80;
        x += 0.5;
        x=floor(x);
        printf("$%.2lf\n", (double)x/100);
    }
}