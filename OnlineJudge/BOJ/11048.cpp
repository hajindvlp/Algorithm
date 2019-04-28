#include <stdio.h>

int n, m, a[1001][1001], d[1001][1001];

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
        {
            if(d[i][j]<a[i][j]+d[i-1][j])
                d[i][j] = a[i][j]+d[i-1][j];
            if(d[i][j]<a[i][j]+d[i][j-1])
                d[i][j] = a[i][j]+d[i][j-1];
            if(d[i][j]<a[i][j]+d[i-1][j-1])
                d[i][j] = a[i][j]+d[i-1][j-1];
        }

    printf("%d", d[n][m]);
}
