#include <stdio.h>
#define INF 1000000

int n, m, a[1001][1001];
int dist[1001], visit[1001], sum, cnt, path[1001], indg[1001], mn, ans[1001], tmp;

int main()
{
    int i, j;
    int x, y, z, v;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] = z;
        indg[y]++;
    }

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(visit[j] == 0 && indg[j]<mn)
            {
                mn = indg[j];
                v = j;
            }
        visit[v] = 1;
        for(j=1 ; j<=n ; j++)
            if(visit[j] == 0 && a[v][j]!=INF && dist[j]<dist[v]+a[v][j])
            {
                dist[j] = dist[v]+a[v][j];
                path[j] = v;
                indg[j]--;
            }
    }


    for(i=1 ; i<=n ; i++)
        if(dist[i]+a[i][1]<INF && dist[1]<dist[i]+a[i][1])
        {
            path[1] = i;
            dist[1] = dist[i]+a[i][1];
        }

    tmp = 1;
    do
    {
        cnt++;
        ans[cnt] = tmp;
        tmp = path[tmp];
    }while(tmp != 1);

    printf("%d\n", dist[1]);
    printf("%d\n1 ", cnt+1);
    for(i=cnt ; i>=1 ; i--)
        printf("%d ", ans[i]);
    return 0;
}
