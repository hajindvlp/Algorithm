#include <stdio.h>

int a[301][301], d[301][301];
int n, m, k;

int main()
{
    int i, j;
    int x1, y1, x2, y2;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]), d[i][j] = a[i][j]+d[i-1][j]+d[i][j-1]-d[i-1][j-1];

    scanf("%d", &k);
    for(i=1 ; i<=k ; i++)
    {
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        printf("%d\n", d[y2][x2]-d[y1-1][x2]-d[y2][x1-1]+d[y1-1][x1-1]);
    }
    return 0;
}
