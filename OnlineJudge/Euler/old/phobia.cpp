#include <stdio.h>
#define INF 1000000000

int a[101][101], n, m, q;
int qu[10001][3];

int mx(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int main()
{
    int i, j, k;
    int x, y, z;

    scanf("%d %d %d", &n, &m, &q);
    for(i=1 ; i<=100 ; i++)
        for(j=1 ; j<=100 ; j++)
            a[i][j] = INF;
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] = z;
        a[y][x] = z;
    }
    for(i=1 ; i<=q ; i++)
        scanf("%d %d", &qu[i][1], &qu[i][2]);

    for(k=1 ; k<=n ; k++)
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
                if(a[i][j]>a[i][k] && a[i][j]>a[k][j] && i!=j)
                    a[i][j] = mx(a[i][k], a[k][j]);

    for(i=1 ; i<=q ; i++)
    {
        if(a[qu[i][1]][qu[i][2]] < INF)
            printf("%d\n", a[qu[i][1]][qu[i][2]]);
        else
            printf("no path\n");
    }
    return 0;
}
