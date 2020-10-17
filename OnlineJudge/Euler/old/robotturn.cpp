#include <stdio.h>
#include <queue>
#define INF 100000000
using namespace std;

queue<int> Q;
int n, m, a[61][61], pp;
int sy, sx, ey, ex;
int d[61][61], dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main()
{
    int i, j;
    int yy, xx, ty, tx;

    scanf("%d %d", &m, &n);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            d[i][j] = INF;

    Q.push(sy);
    Q.push(sx);
    Q.push(-1);
    d[sy][sx] = 0;
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        pp = Q.front(), Q.pop();
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx]!=1)
            {
                if(pp == -1 && d[ty][tx]>d[yy][xx])
                {
                    d[ty][tx] = d[yy][xx];
                    Q.push(ty);
                    Q.push(tx);
                    Q.push(i);
                }
                else if(i!=pp && d[ty][tx]>d[yy][xx]+1)
                {
                    d[ty][tx] = d[yy][xx]+1;
                    Q.push(ty);
                    Q.push(tx);
                    Q.push(i);
                }
                else if(i==pp && d[ty][tx]>d[yy][xx])
                {
                    d[ty][tx] = d[yy][xx];
                    Q.push(ty);
                    Q.push(tx);
                    Q.push(i);
                }
            }
        }
    }
    printf("%d", d[ey][ex]);
    return 0;
}
