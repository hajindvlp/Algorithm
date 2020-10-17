#include <stdio.h>
#include <math.h>
#define INF 10000000

int n, dot[751][3], m;
double a[751][751];
int tmp, v, mn, visit[751], dist[751];

int cnt, path[751], apath[751];

int main()
{
    int i, j;
    int x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &dot[i][1], &dot[i][2]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;

    for(i=1 ; i<=n-1 ; i++)
        for(j=i+1 ; j<=n ; j++)
            if(i!=j)
                a[j][i] = a[i][j] = sqrt(pow(dot[i][1]-dot[j][1], 2.0)+pow(dot[i][2]-dot[j][2], 2.0));

    scanf("%d", &m);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y] = a[y][x] = 0;
    }

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[1] = 0;

    for(i=1 ; i<=n ; i++)
    {
        tmp = v;
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(dist[j]<mn)
            {
                v = j;
                mn = dist[j];
            }
        visit[v] = 1;
        cnt++;
        apath[cnt] = path[v];
        for(j=1 ; j<=n ; j++)
            if(visit[j]!=1 && dist[j]<a[v][j])
            {
                dist[j] = a[v][j];
                path[j] = v;
            }
    }
    for(i=1 ; i<=n ; i++)
        printf("%lf ", dist[i]);
    return 0;
}
