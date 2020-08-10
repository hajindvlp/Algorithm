#include <stdio.h>

int main() {
    long long int a, b, c;

    scanf("%lld%lld%lld", &a,&b,&c);
    printf("%lld", ((a%c)?1+a/c:a/c)*((b%c)?b/c+1:b/c));
}   