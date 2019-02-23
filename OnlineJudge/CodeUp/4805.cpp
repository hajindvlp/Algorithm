#include <stdio.h>
#define INF 1000000000

int a[101][101], d[101][101];
int n, m, cnt;

int main()
{
    int x, y;
    int i, j, k;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = d[i][j] = INF;

    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[y][x] = 1, d[x][y] = 1;

    for(k=1 ; k<=n ; k++)
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
            {
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j] = a[i][k]+a[k][j];
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j] = d[i][k]+d[k][j];
            }

    for(i=1 ; i<=n ; i++)
    {
        cnt = 0;
        for(j=1 ; j<=n ; j++)
            if(a[i][j] == INF && d[i][j]==INF)
                cnt++;
        printf("%d\n", cnt-1);
    }
    return 0;
}
