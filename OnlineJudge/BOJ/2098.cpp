#include <stdio.h>
#define INF 100000000

int n, a[21][21], d[21], visit[21];

int main()
{
    int i, j;
    int v, mn;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) d[i] = INF;
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(!visit[j] && dist[j]<mn)
            {
                mn = dist[j];
                v = j;
            }
        visit[v] = 1;
        for(j=1 ; j<=n ; j++)
            if(visit[j] == 0 && d[j]>d[v]+a[v][j])
                d[j] = d[v]+a[v][j];
    }

    for(i=1 ; i<)
}
