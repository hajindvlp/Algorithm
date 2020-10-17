#include <stdio.h>
#define INF 1000000

int dist[1001], visit[1001], a[1001][1001], n, m, sx;

int main()
{
    int i, x, y, z, mx, j, v;

    scanf("%d %d %d", &n, &m, &sx);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        if(a[x][y]!=INF && a[x][y]>z)
        {
            a[x][y] = z;
            a[y][x] = z;
        }
        else if(a[x][y] == INF)
        {
            a[x][y] = z;
            a[y][x] = z;
        }
    }

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[sx] = 0;

    for(i=1 ; i<=n ; i++)
    {
        mx = INF;
        for(j=1 ; j<=n ; j++)
            if(dist[j]<mx && visit[j]==0)
            {
                mx = dist[j];
                v = j;
            }
        visit[v] = 1;
        for(j=1 ; j<=n ; j++)
            if(dist[j]>dist[v]+a[v][j])
                dist[j]=dist[v]+a[v][j];
    }

    mx = 0;
    for(i=1 ; i<=n ; i++)
        if(dist[i]>mx)
            mx = dist[i];
    printf("%d", mx*2);
    return 0;
}
