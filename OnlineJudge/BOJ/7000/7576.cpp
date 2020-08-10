#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

int n, m, a[1001][1001];
int d[1001][1001];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
queue<int> Q;

void bfs()
{
    int yy, xx, ty, tx, i;

    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && d[ty][tx]>d[yy][xx]+1 && a[ty][tx]==0)
            {
                d[ty][tx] = d[yy][xx]+1;
                Q.push(ty);
                Q.push(tx);
            }
        }
    }
}

int main()
{
    int i, j, mx = 0;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
        {
            scanf("%d", &a[i][j]);
            d[i][j] = INF;
            if(a[i][j] == 1)
                Q.push(i), Q.push(j), d[i][j] = 0;
        }

    bfs();

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
        {
            if(d[i][j] == INF && a[i][j] == 0)
            {
                printf("-1");
                return 0;
            }
            if(a[i][j] == 0)
                mx = max(mx, d[i][j]);
        }
    printf("%d", mx);
    return 0;
}
