#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

queue<int> Q;
int n, m;
int a[101][101], d[101][101];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

int main()
{
    int i, j;
    char tmp[104];
    int yy, xx, ty, tx;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=m ; j++)
            a[i][j] = tmp[j]-'0', d[i][j] = INF;
    }

    d[1][1] = 1;
    Q.push(1);
    Q.push(1);
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && d[ty][tx]>d[yy][xx]+1 && a[ty][tx] == 1)
            {
                Q.push(ty);
                Q.push(tx);
                d[ty][tx] = d[yy][xx]+1;
            }
        }
    }

    printf("%d", d[n][m]);
    return 0;
}