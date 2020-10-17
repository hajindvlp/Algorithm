#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

queue<int> Q;
int a[51][51], d[51][51];
int sy, sx, ey, ex , cnt, n;
int dy[4]={0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
pair<int, int> path[51][51], ap[2501];

int main()
{
    int i, j;
    int xx, yy, ty, tx;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]), d[i][j] = INF;
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    d[sy][sx] = a[sy][sx];

    Q.push(sy);
    Q.push(sx);
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();

        for(i=0 ; i<=3 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=n && d[ty][tx]>d[yy][xx]+a[ty][tx] && a[ty][tx]!=0)
            {
                d[ty][tx] = d[yy][xx]+a[ty][tx];
                path[ty][tx] = make_pair(yy, xx);
                Q.push(ty);
                Q.push(tx);
            }
        }
    }

    if(d[ey][ex] >= INF)
    {
        printf("-1");
        return 0;
    }

    yy = ey;
    xx = ex;
    while(!(yy == sy && xx == sx))
    {
        cnt++;
        ap[cnt] = make_pair(yy, xx);
        ty = path[yy][xx].first;
        tx = path[yy][xx].second;
        yy = ty;
        xx = tx;
    }
    printf("%d\n", cnt+1);
    printf("%d %d\n", sx, sy);
    for(i=cnt ; i>=1 ; i--)
        printf("%d %d \n", ap[i].second, ap[i].first);
    return 0;
}
