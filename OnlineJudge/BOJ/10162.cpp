#include <stdio.h>

int main() {
    int a;

    scanf("%d", &a);
    if(a%10 == 0) {
        printf("%d ", a/300);
        a%=300;
        printf("%d ", a/60);
        a%=60;
        printf("%d ", a/10);
    } else {
        printf("-1");
    }
}