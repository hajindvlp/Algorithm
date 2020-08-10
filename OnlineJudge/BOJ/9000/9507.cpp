#include <stdio.h>

int t, a;
long long int d[68];

int main()
{
    int i;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(i=4 ; i<=67 ; i++)
        d[i] = d[i-1]+d[i-2]+d[i-3]+d[i-4];

    scanf("%d", &t);
    for(i=1 ; i<=t ; i++)
        scanf("%d", &a), printf("%lld\n", d[a]);
}
