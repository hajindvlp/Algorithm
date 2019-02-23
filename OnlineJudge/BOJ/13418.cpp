#include <stdio.h>
#define INF 1000000000

int n, m;
int a[1001][1001], dist[1001], visit[1001];
int mnsum, mxsum;

int main()
{
    int i, j;
    int x, y, z;
    int mn, v;

    scanf("%d %d", &n, &m);
    for(i=0 ; i<=n ; i++)
        for(j=0 ; j<=n ; j++)
            a[i][j] = INF;

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] = z;
        a[y][x] = z;
    }

    for(i=0; i<=n ; i++)
        dist[i] = INF;
    dist[0] = 1-a[1][0];

    for(i=0 ; i<=n ; i++)
    {
        mn = INF;
        for(j=0 ; j<=n ; j++)
            if(visit[j] == 0 && dist[j]<mn)
                mn = dist[j], v = j;
        mnsum+=mn;
        visit[v] = 1;
        for(j=0 ; j<=n ; j++)
            if(visit[j] == 0 && dist[j]>1-a[v][j] && 1-a[v][j]>=0)
                dist[j] = 1-a[v][j];
    }

    for(i=0 ; i<=n ; i++)
        dist[i] = INF, visit[i] = 0;
    dist[0] = a[1][0];

    for(i=0 ; i<=n ; i++)
    {
        mn = INF;
        for(j=0 ; j<=n ; j++)
            if(visit[j] == 0 && dist[j]<mn)
                mn = dist[j], v = j;
        mxsum+=mn;
        visit[v] = 1;
        for(j=0 ; j<=n ; j++)
            if(visit[j] == 0 && dist[j]>a[v][j])
                dist[j] = a[v][j];
    }
    printf("%d", mxsum*mxsum - mnsum*mnsum);
    return 0;
}
