#include <stdio.h>

unsigned long long int comin(int a, int b)
{
    int i;
    unsigned long long int v = 1;

    for(i=a ; i>a-b ; i--)
        v*=i;
    for(i=1 ; i<=b ; i++)
        v/=i;
    return v;
}

int main()
{
    int n, i;
    int a, b;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%llu\n", comin(b, a));
    }
    return 0;
}
