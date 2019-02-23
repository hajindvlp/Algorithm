#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

int n, m;
int a[101][101], dist[101];
queue<int> Q;

int main()
{
    int i;
    int x, y, sx, ex;

    scanf("%d %d %d %d", &n, &sx, &ex, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;
    for(i=1 ; i<=n ; i++)
        dist[i] = INF;

    dist[sx] = 0;
    Q.push(sx);
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        for(i=1 ; i<=n ; i++)
            if(a[x][i] == 1 && dist[i]>dist[x]+a[x][i])
                dist[i] = dist[x]+a[x][i], Q.push(i);
    }
    if(dist[ex] == INF)
        printf("-1");
    else
        printf("%d", dist[ex]);
    return 0;
}
