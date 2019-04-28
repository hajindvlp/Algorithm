#include <stdio.h>

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int n, i;
    int a[51], gg;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), gg = (i == 1) ? a[i] : (gg*a[i])/gcd(a[i], gg);
    for(i=1 ; i<=n ; i++)
        if(gg == a[i])
            gg*=2;
    printf("%d", gg);
}
