#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

queue<int> Q;
int n, m;
int ey, ex, sy, sx, yy, xx, ty, tx;
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
int a[301][301], d[301][301], w[30][4];

int main()
{
    int i, j;
    char tmp[302];

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=m ; j++)
        {
            d[i][j] = INF;
            if(tmp[j] == '=')
                ey = i, ex = j;
            else if(tmp[j] == '@')
                sy = i, sx = j;
            else if(tmp[j] == '#')
                a[i][j] = -1;
            else if(tmp[j]>='A' && tmp[j]<='Z')
            {
                if(w[tmp[j]-'A'+1][0]!=0)
                    w[tmp[j]-'A'+1][2] = i, w[tmp[j]-'A'+1][3] = j;
                else
                    w[tmp[j]-'A'+1][0] = i, w[tmp[j]-'A'+1][1] = j;
                a[i][j] = tmp[j]-'A'+1;
            }
        }
    }

    d[sy][sx] = 0;
    Q.push(sy);
    Q.push(sx);
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx]!=-1)
            {
                if(a[ty][tx] == 0 && d[ty][tx]>d[yy][xx]+1)
                {
                    d[ty][tx] = d[yy][xx]+1;
                    Q.push(ty);
                    Q.push(tx);
                }
                else if(a[ty][tx]>0)
                {
                    if(ty == w[a[ty][tx]][0] && tx == w[a[ty][tx]][1] && d[w[a[ty][tx]][2]][w[a[ty][tx]][3]]>d[yy][xx]+1)
                    {
                        d[w[a[ty][tx]][2]][w[a[ty][tx]][3]] = d[yy][xx]+1;
                        Q.push(w[a[ty][tx]][2]);
                        Q.push(w[a[ty][tx]][3]);
                    }
                    else if(ty == w[a[ty][tx]][2] && tx == w[a[ty][tx]][3] && d[w[a[ty][tx]][0]][w[a[ty][tx]][1]]>d[yy][xx]+1)
                    {
                        d[w[a[ty][tx]][0]][w[a[ty][tx]][1]] = d[yy][xx]+1;
                        Q.push(w[a[ty][tx]][0]);
                        Q.push(w[a[ty][tx]][1]);
                    }
                }
            }
        }
    }
    /*
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
        {
            if(d[i][j] == INF)
                printf(". ");
            else
                printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=1 ; i<=26 ; i++)
    {
        for(j=0 ; j<4 ; j++)
            printf("%d ", w[i][j]);
        printf("\n");
    }*/

    printf("%d", d[ey][ex]);
    return 0;
}
