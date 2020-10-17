#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

queue<int> Q;
int n, m;
int a[1001][1001], dist[1001][1001], path[1001][1001][3];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main()
{
    int i, j;
    int yy, xx, ty, tx, h;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]), dist[i][j] = INF;

    Q.push(n);
    Q.push(0);
    Q.push(0);
    dist[n][0] = 0;
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        h = Q.front(), Q.pop();

        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx] == 1 && !h && dist[ty][tx]>dist[yy][xx]+1)
            {
                dist[ty][tx] = dist[yy][xx]+1;
                Q.push(ty);
                Q.push(tx);
                Q.push(1);
                if(path[ty][tx][0] == 0 && path[ty][tx][1] == 0)
                    path[ty][tx][0] = ty, path[ty][tx][1] = tx,  path[ty][tx][2] = 1;
                else if(ty<path[ty][tx][0] && tx<path[ty][tx][1])
                    path[ty][tx][0] = ty, path[ty][tx][1] = tx,  path[ty][tx][2] = 1;
            }
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx] == 0 && dist[ty][tx]>dist[yy][xx]+1)
            {
                dist[ty][tx] = dist[yy][xx]+1;
                Q.push(ty);
                Q.push(tx);
                Q.push(h);
                if(path[ty][tx][2] == 1)
                    if(path[ty][tx][0]>path[yy][xx][0] && path[ty][tx][1]>path[yy][xx][1])
                        path[ty][tx][0]=path[yy][xx][0], path[ty][tx][1]=path[yy][xx][1];
            }
        }
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
            printf("{%d %d}", path[i][j][0], path[i][j][1]);
        printf("\n");
    }
    printf("%d %d\n", path[1][m][0], path[1][m][1]);
    printf("%d", dist[1][m]);

    return 0;
}
