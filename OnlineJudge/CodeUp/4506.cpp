#include <stdio.h>

int n;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int x;

    scanf("%d %d", &n, &x);
    printf("%d\n%d", gcd(n, x), n*x/gcd(n, x));
}
