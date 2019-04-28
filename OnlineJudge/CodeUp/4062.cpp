#include <stdio.h>

int n, g, l = 1;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int i, x;

    scanf("%d %d", &n, &x);
    g = l = x;
    for(i=1 ; i<=n-1 ; i++)
    {
        scanf("%d", &x);
        g = gcd(g, x);
        l = l*x/gcd(l, x);
    }
    printf("%d\n%d", g, l);
}
