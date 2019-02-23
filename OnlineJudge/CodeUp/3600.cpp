#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

int n, m;
int dist[1001][1001];
int sy, sx, ey, ex, yy, xx, ty, tx;
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
queue<int> Q;

int main()
{
    int i, j;

    scanf("%d %d %d %d %d", &n, &sx, &sy, &ex, &ey);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            dist[i][j] = INF;

    dist[sy][sx] = 0;
    Q.push(sy);
    Q.push(sx);
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();

        for(i=0 ; i<8 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=n && dist[ty][tx]>dist[yy][xx]+1)
            {
                dist[ty][tx] = dist[yy][xx]+1;
                Q.push(ty), Q.push(tx);
            }
        }
    }
    printf("%d", dist[ey][ex]);
    return 0;
}
