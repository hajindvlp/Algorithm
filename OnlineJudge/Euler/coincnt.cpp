#include <stdio.h>

int n, a[21], m;
unsigned long long int d[10001];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);

    d[0] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=a[i] ; j<=m ; j++)
            d[j]+=d[j-a[i]];
    printf("%llu", d[m]);
    return 0;
}
