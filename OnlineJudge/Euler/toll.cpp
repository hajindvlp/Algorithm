#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;

int n, m;
int a[251][251], cost[251], b[251][251];
int q[10001][3], qn;

int main()
{
    int i, j, k;
    int x, y, z;

    scanf("%d %d %d", &n, &m, &qn);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &cost[i]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        if(a[x][y]>z)
            a[x][y] = a[y][x] = z;
    }

    for(i=1 ; i<=qn ; i++)
        scanf("%d %d", &q[i][1], &q[i][2]);

    for(k=1 ; k<=n ; k++)
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
                if(a[i][j]+b[i][j]>a[i][k]+a[k][j]+max(max(b[i][j], b[i][k]), b[k][j]))
                    a[i][j] = a[i][k]+a[k][j], b[i][j] =max(max(b[i][j], b[i][k]), b[k][j]);

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    for(i=1 ; i<=qn ; i++)
        printf("%d\n", a[q[i][1]][q[i][2]]+b[i][j]);
    return 0;
}
