#include <stdio.h>
#define INF 10000000

int n, a[101][101];
int visit[101], dist[101], sum, mn, v;

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
    {
        dist[i] = INF;
        visit[i] = 0;
    }
    dist[1] = 0;

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(dist[j]<mn && visit[j] == 0)
            {
                v = j;
                mn = dist[j];
            }
        visit[v] = 1;
        sum+=mn;
        for(j=1 ; j<=n ; j++)
            if(dist[j]>a[v][j] && visit[j] == 0)
                dist[j] = a[v][j];
    }

    printf("%d", sum);
    return 0;
}
