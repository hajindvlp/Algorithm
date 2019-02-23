#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

queue<int> Q;
int n, m, l;
int a[101][101], d[101][101], path[101][101];
int dy[4] = {0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
int sy, sx, ey, ex, cnt;
pair<int, int> v[10001];

bool bfs()
{
    bool ok = false;
    int xx, yy, ty, tx;
    int i;

    cnt = 0, ok = false;
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && d[ty][tx]>d[yy][xx]+1 && a[ty][tx]!=-1)
            {
                d[ty][tx] = d[yy][xx]+1;
                path[ty][tx] = i;
                if(d[ty][tx]%l == 0)
                    v[++cnt] = make_pair(ty, tx);
                Q.push(ty);
                Q.push(tx);
            }
            ok = true;
        }
    }
    return ok;
}

int main()
{
    int i ,j, k;
    char c[102];

    scanf("%d %d %d", &n, &m, &l);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &c[1]);
        for(j=1 ; j<=m ; j++)
        {
            if(c[j] == 'Y')
                sy = i, sx = j, Q.push(i), Q.push(j);
            else if(c[j] == 'S')
                ey = i, ex = j;
            else if(c[j] == 'F')
                a[i][j] = -1;
        }
    }

    d[sy][sx] = 0;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            d[i][j] = INF;

    while(bfs())
    {
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=m ; j++)
                if(a[i][j] == -1)
                    for(k=0 ; k<4 ; k++)
                        a[i+dy[k]][j+dx[k]] = -1;
        for(i=1 ; i<=cnt ; i++)
            if(a[v[i].first][v[i].second]!=-1)
                Q.push(v[i].first), Q.push(v[i].second);
    }

    printf("%d\n", d[ey][ex]);
    while(ex != sx && ey != sy)
    {
        printf("%d\n", path[ey][ex]);
        ex = ex-dx[(path[ey][ex]+2)%4];
        ey = ey-dx[(path[ey][ex]+2)%4];
    }
    return 0;
}