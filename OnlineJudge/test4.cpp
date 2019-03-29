#include <stdio.h>
#define INF 1000000000

int dist[5001], a[5001][5001], visit[5001];
int n, m;

int main()
{
    int i, j, mn, x, y, v;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[1] = 0;

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(mn>dist[j] && visit[j] == 0)
                mn = dist[j], v = j;
        visit[v] = 1;
        for(j=1 ; j<=n ; j++)
            if(visit[j] == 0 && dist[j]>dist[v]+a[v][j])
                dist[j] = dist[v]+a[v][j];
    }

    mn = 0;
    for(i=1 ; i<=n ; i++)
        if(mn<dist[i])
            mn = dist[i];
    printf("%d\n", mn);
    for(i=1 ; i<=n ; i++)
        if(mn == dist[i])
            printf("%d ", i);
    return 0;
}
