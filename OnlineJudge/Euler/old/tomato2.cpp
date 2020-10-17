#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

queue<int> Q;
int n, m, h, mx;
int a[101][101][101], d[101][101][101];
int dz[6]={0, 0, 0, 0, 1, -1}, dy[6]={0, 0, 1, -1, 0, 0}, dx[6]={1, -1, 0, 0, 0, 0};

int main()
{
    int i, j, k;
    int zz, yy, xx, tz, ty, tx;

    scanf("%d %d %d", &m, &n, &h);
    for(i=1 ; i<=h ; i++)
        for(j=1 ; j<=n ; j++)
            for(k=1 ; k<=m ; k++)
            {
                d[i][j][k] = INF;
                scanf("%d", &a[i][j][k]);
                if(a[i][j][k] == 1)
                    Q.push(i), Q.push(j), Q.push(k), d[i][j][k] = 0;
                else if(a[i][j][k] == -1)
                    d[i][j][k] = -1;
            }

    while(!Q.empty())
    {
        zz = Q.front(), Q.pop();
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        for(i=0 ; i<6 ; i++)
        {
            tz = zz+dz[i];
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(tz>0 && tz<=h && ty>0 && ty<=n && tx>0 && tx<=m && d[tz][ty][tx]>d[zz][yy][xx]+1 && a[tz][ty][tx] == 0)
            {
                Q.push(tz);
                Q.push(ty);
                Q.push(tx);
                d[tz][ty][tx] = d[zz][yy][xx]+1;
                if(d[tz][ty][tx]>mx)
                    mx = d[tz][ty][tx];
            }
        }
    }

    for(i=1 ; i<=h ; i++)
        for(j=1 ; j<=n ; j++)
            for(k=1 ; k<=m ; k++)
                if(d[i][j][k] >= INF)
                {
                    printf("-1");
                    return 0;
                }

    printf("%d", mx);
    return 0;
}
