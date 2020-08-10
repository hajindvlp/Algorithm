#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    b-=45;

    if(b<0) b = (b+60)%60, a = (a+23)%24;
    
    printf("%d %d", a, b);
}