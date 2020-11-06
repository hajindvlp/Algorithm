#include <stdio.h>
#include <queue>

using namespace std;

queue<int> Q;

int n, m;
int a[101][101];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int cnt;

void flood(int sy, int sx)
{
    int xx, yy, tx, ty, i;

    cnt++;
    Q.push(sy);
    Q.push(sx);
    while(!Q.empty())
    {
        yy = Q.front();Q.pop();
        xx = Q.front();Q.pop();
        for(i=0 ; i<=3 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && tx>0 &&ty<=n && tx<=m && a[ty][tx] == 1)
            {
                Q.push(ty);
                Q.push(tx);
                a[ty][tx] = 0;
            }
        }
    }
}

int main()
{
    int i, j;
    char x[102];

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &x[1]);
        for(j=1 ; j<=m ; j++)
            if(x[j] == '#')
                a[i][j] = 1;
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(a[i][j] == 1)
                flood(i, j);

    printf("%d", cnt);
}
