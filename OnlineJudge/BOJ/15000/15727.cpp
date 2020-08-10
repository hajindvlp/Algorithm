#include <stdio.h>

int main() {
    int a, ans;

    scanf("%d", &a);
    ans = a/5;
    if(a%5) ans+=1;
    printf("%d", ans);
}