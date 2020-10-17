#include <stdio.h>
#include <math.h>
#define INF 1000000

int n, m;
double a[1001][1001], mn, dist[1001], sum;
int dot[1001][3];
int visit[1001], v;

int main()
{
    int i, j;
    int x, y;

    scanf("%d %d" ,&n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &dot[i][1], &dot[i][2]);

    for(i=1 ; i<=n-1 ; i++)
        for(j=i+1 ; j<=n ; j++)
            a[i][j] = a[j][i] = sqrt(pow(dot[i][1]-dot[j][1], 2.0)+pow(dot[i][2]-dot[j][2], 2.0));

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[1] = 0;

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y] = a[y][x] = 0;
    }

    for(i=1 ;  i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(!visit[j]&& mn>dist[j])
            {
                mn = dist[j];
                v = j;
            }
        visit[v] = 1;
        sum+=mn;
        for(j=1 ; j<=n ; j++)
            if(dist[j]>a[v][j])
                dist[j] = a[v][j];
    }
    printf("%.2f", sum);
}
