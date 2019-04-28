#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;
int n, m, cnt, asum, tsum;
int a[101][101], d[101][101];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

bool check()
{
    int i, j;

    tsum = 0;
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(a[i][j] ==  1)
                tsum++;
    if(tsum>0)
    {
        asum = tsum;
        return true;
    }
    return false;
}

int main()
{
    int i, j, k;
    int yy, xx, ty, tx;
    int sum;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]);

    while(check())
    {
        cnt++;
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=m ; j++)
                d[i][j] = 0;

        Q.push(1);
        Q.push(1);
        while(!Q.empty())
        {
            yy = Q.front(), Q.pop();
            xx = Q.front(), Q.pop();
            d[yy][xx]=1;
            for(i=0 ; i<4 ; i++)
            {
                ty = yy+dy[i];
                tx = xx+dx[i];
                if(ty>0 && ty<=n && tx>0 && tx<=m && d[ty][tx] == 0 && a[ty][tx]!=1)
                {
                    Q.push(ty);
                    Q.push(tx);
                }
            }
        }

        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=m ; j++)
                if(a[i][j] == 1)
                    for(k=0 ; k<4 ; k++)
                        if(i+dy[k]>0 && i+dy[k]<=n && j+dx[k]>0 && j+dx[k]<=m && d[i+dy[k]][j+dx[k]])
                        {
                            a[i][j] = 0;
                            break;
                        }
    }
    printf("%d\n%d", cnt, asum);
}
