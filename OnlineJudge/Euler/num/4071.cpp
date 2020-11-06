#include <stdio.h>
#define INF 2100000000

int n, dist[101], cost[101], d[101], dsum[101];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &dist[i]);
    }
    for(i=1 ; i<=n+1 ; i++)
    {
        d[i] = INF;
        dsum[i] = dsum[i-1]+dist[i-1];
    }
    for(i=1 ; i<=n ; i++)
        scanf("%d", &cost[i]);

    d[1] = 0;
    for(i=1 ; i<=n+1 ; i++)
    {
        for(j=1 ; j<=i-1 ; j++)
            if(dsum[i]-dsum[j]<=50 && d[j]+(dsum[i]-dsum[j])*cost[j]<d[i])
            {
                d[i] = (dsum[i]-dsum[j])*cost[j]+d[j];
                printf("%d = %d + %d :: %d -> %d\n", d[i], (dsum[i]-dsum[j])*cost[j], d[j], j, i);
            }
    }
    for(i=1 ; i<=n+1 ; i++)
        printf("%d ", d[i]);
    return 0;
}
