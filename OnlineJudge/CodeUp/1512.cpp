#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;
int a[101][101], sx, sy, n;

int main()
{
    int i, j;
    int yy, xx, ty, tx;
    int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

    scanf("%d %d %d", &n, &sy, &sx);
    a[sy][sx] = 1;
    Q.push(sy), Q.push(sx);
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=n && a[ty][tx]==0)
            {
                a[ty][tx] = a[yy][xx]+1;
                Q.push(ty), Q.push(tx);
            }
        }
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
