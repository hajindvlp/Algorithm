#include <stdio.h>
#define INF 100000000

int n, m;
int a[101][101];
int dist[101], visit[101];
int apath[101], path[101];

void init()
{
    int i;

    for(i=1 ; i<=100 ; i++)
        dist[i] = INF, visit[i] = 0;
}

int mst(bool is, int x, int y)
{
    int i, j;
    int sum = 0;
    int mn, v;

    sum = 0;
    dist[1] = 0;
    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(dist[j]<mn && visit[j]==0)
            {
                mn = dist[j];
                v = j;
            }
        visit[v] = 1;
        sum+=mn;
        for(j=1 ; j<=n ; j++)
            if(dist[j]>a[v][j] && visit[j]==0 && !((v==x && j==y) || (v==y && j==x)))
            {
                dist[j] = a[v][j];
                if(is)
                    path[j] = v;
            }
    }
    if(sum>INF)
        return INF;
    return sum;
}

int main()
{
    int x, y, z;
    int i, j;
    int mx = INF, tsum, asum;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;

    for(i=1 ; i<=m ; i++)
        scanf("%d %d %d", &x, &y, &z), a[x][y] = a[y][x] = z;

    init();
    asum = mst(1, 0, 0);
    for(i=2 ; i<=n ; i++)
    {
        init();
        tsum = mst(0, i, path[i]);
        if(mx>tsum)
            mx = tsum;
    }
    printf("%d %d", asum, mx);
    return 0;
}
