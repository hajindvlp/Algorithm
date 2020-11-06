#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

queue<pair<int, int> > Q;
int n, m, l;
int a[101][101], d[101][101], path[101][101], ua[101][101];
int dy[4] = {0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
int sy, sx, ey, ex;

bool bfs() {
    int yy, xx, ty, tx;
    int i;

    while(!Q.empty()) {
        yy = Q.front().first;
        xx = Q.front().second;
        Q.pop();
        for(i=0 ; i<4 ; i++) {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx]!=-1 && d[yy][xx]<l && d[ty][tx] > d[yy][xx]+1) {
                Q.push({ty, tx});
                d[ty][tx] = d[yy][xx]+1;
                path[ty][tx] = i;
            }
        }
    }

    if(d[ey][ex] != INF) {
        return false;
    }
    return true;
}

int main()
{
    int i ,j, k;
    int yy, xx, ty, tx;
    char c[102];

    scanf("%d %d %d", &n, &m, &l);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &c[1]);
        for(j=1 ; j<=m ; j++)
        {
            if(c[j] == 'Y')
                sy = i, sx = j;
            else if(c[j] == 'S')
                ey = i, ex = j;
            else if(c[j] == 'F')
                a[i][j] = -1;
        }
    }

    Q.push({sy, sx});
    for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++) d[i][j] = INF;
    d[sy][sx] = 0;

    while(bfs())
    {   
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=m ; j++)
                if(a[i][j] == -1)
                    for(k=0 ; k<4 ; k++) {
                        ty = i+dy[k];
                        tx = j+dx[k];
                        if(ty>0 && ty<=n && tx>0 && tx<=m) ua[ty][tx] = -1;
                    }
        for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++) if(ua[i][j] == -1) a[i][j] = -1;

        for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++) if(d[i][j] ==  && a[i][j] != -1) Q.push({i, j});

        printf("\n%d\n", Q.size());
        for(i=1;  i<=n ; i++) {
            for(j=1 ; j<=m ; j++) printf("%2d ", d[i][j]==INF ? -1 : d[i][j]);
            printf("\n");
        }
        for(i=1;  i<=n ; i++) {
            for(j=1 ; j<=m ; j++) printf("%2d ", a[i][j]==-1 ? -1 : a[i][j]);
            printf("\n");
        }
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