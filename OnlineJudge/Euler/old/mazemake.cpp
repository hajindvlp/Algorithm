#include <stdio.h>
#include <queue>
#define INF 100000000
using namespace std;

queue<int> Q;
int n, a[51][51];
int d[51][51], h[51][51], visit[51][51];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main()
{
    char tmp[51];
    int i, j;
    int yy, xx, ty, tx, cnt;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=n ; j++)
            a[i][j] = 1-(tmp[j]-'0'), d[i][j] = h[i][j] = INF;
    }
    d[1][1] = 0;
    h[1][1] = 0;

    Q.push(1);
    Q.push(1);
    Q.push(0);
    while(!Q.empty())
    {
        yy = Q.front();
        Q.pop();
        xx = Q.front();
        Q.pop();
        cnt = Q.front();
        Q.pop();
        for(i=0 ; i<=3 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=n)
            {
                if(a[yy][xx] == 0)
                {
                    if(visit[ty][tx] == 0 || h[ty][tx]>cnt)
                    {
                        d[ty][tx] = d[yy][xx]+1;
                        h[ty][tx] = cnt;
                        visit[ty][tx] = 1;
                        Q.push(ty);
                        Q.push(tx);
                        Q.push(cnt);
                    }
                    else if(visit[ty][tx] == 1 && h[ty][tx] == cnt && d[ty][tx]>d[yy][xx]+1)
                    {
                        d[ty][tx] = d[yy][xx]+1;
                        Q.push(ty);
                        Q.push(tx);
                        Q.push(cnt);
                    }
                }
                else
                {
                    if(visit[ty][tx] == 0 || h[ty][tx]>cnt+1)
                    {
                        d[ty][tx] = d[yy][xx]+1;
                        h[ty][tx] = cnt+1;
                        visit[ty][tx] = 1;
                        Q.push(ty);
                        Q.push(tx);
                        Q.push(cnt+1);
                    }
                    else if(visit[ty][tx] == 1 && h[ty][tx] == cnt+1 && d[ty][tx]>d[yy][xx]+1)
                    {
                        d[ty][tx] = d[yy][xx]+1;
                        Q.push(ty);
                        Q.push(tx);
                        Q.push(cnt+1);
                    }
                }
            }
        }
    }
    printf("%d", h[n][n]);
    return 0;
}
