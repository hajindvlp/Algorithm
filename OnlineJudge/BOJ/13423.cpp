#include <stdio.h>
#define INF 1000000000

int pro()
{
    int n, m, v, k, f, l;
    int x, y, z;
    int i, j, mn, ans, sum;
    int a[101][101], dist[101], visit[101], fl[101];

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] = z;
        a[y][x] = z;
    }

    ans = INF;

    scanf("%d", &f);
    for(i=1 ; i<=f ; i++)
        scanf("%d", &fl[i]);

    for(k=1 ; k<=n ; k++)
    {
        sum = 0;
        for(i=1 ; i<=n ; i++)
            dist[i] = INF, visit[i] = 0;
        dist[k] = 0;

        for(i=1 ; i<=n ; i++)
        {
            mn = INF;
            for(j=1 ; j<=n ; j++)
                if(visit[j] == 0 && dist[j]<mn)
                    mn = dist[j], v = j;
            visit[v] = 1;
            for(j=1 ; j<=n ; j++)
                if(visit[j] == 0 && dist[j]>dist[v]+a[j][v] && j<=n)
                    dist[j] = dist[v]+a[j][v];
        }

        for(i=1 ; i<=f ; i++)
            sum += dist[fl[i]];
        if(sum<ans)
            ans = sum, l = k;
    }
    printf("%d\n", l);
}

int main()
{
    int t, i;

    scanf("%d", &t);
    for(i=1 ; i<=t ; i++)
        pro();
    return 0;
}
