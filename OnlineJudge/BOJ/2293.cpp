#include <stdio.h>

int n, m, a[101], d[10001];

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    d[0] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=a[i] ; j<=m ; j++)
            d[j]+=d[j-a[i]];

    printf("%d", d[m]);
    return 0;
}
