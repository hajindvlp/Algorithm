#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

int n, c;
int d[501][501], a[501][501];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
queue<int> Q;

int main()
{
    int i, j;
    int sx, sy, ex, ey, xx, yy, tx, ty;
    char tmp[505];

    scanf("%d %d", &n, &c);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=n ; j++)
        {
            d[i][j] = INF;
            if(tmp[j] == 'S')
                sy = i, sx = j, a[i][j] = 1;
            else if(tmp[j] == 'T')
                ey = i, ex = j, a[i][j] = 1;
            else if(tmp[j] == '*')
                a[i][j] = c+1;
            else
                a[i][j] = 1;
        }
    }

    Q.push(sy);
    Q.push(sx);
    d[sy][sx] = 0;
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=n && d[ty][tx]>d[yy][xx]+a[ty][tx])
            {
                d[ty][tx] = d[yy][xx]+a[ty][tx];
                Q.push(ty);
                Q.push(tx);
            }
        }
    }

    printf("%d", d[ey][ex]);
    return 0;
}
