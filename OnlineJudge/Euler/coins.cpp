#include <stdio.h>
#define INF 1000000000

int n, m, a[101], d[10001], path[10001], cnt[101];

int main()
{
    int i, j, x;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n ; i++)
        d[i] = INF;

    for(i=1 ; i<=m ; i++)
    {
        for(j=a[i] ; j<=n ; j++)
            if(d[j]>d[j-a[i]]+1)
                d[j] = d[j-a[i]]+1, path[j] = i;
    }

    if(d[n] == INF)
    {
        printf("-1");
        return 0;
    }

    x =  n;
    while(x!=0)
    {
        cnt[path[x]]++;
        x = x-a[path[x]];
    }
    for(i=1 ; i<=m ; i++)
        printf("%d\n", cnt[i]);
    return 0;
}
