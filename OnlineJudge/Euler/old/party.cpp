#include <stdio.h>

int n, a[101][101], d[101][101], v[101], p[101], path[101][101];
int mx, cnt, apath[101];

int main()
{
    int x, y, z;
    int i, j, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        p[x] = y;
        v[x] = z;
        for(j=1 ; j<=n ; j++)
            a[i][j] = 1;
        d[i][i] = v[i];
    }

    for(i=1 ; i<=n ; i++)
    {
        x = i;
        while(p[x])
        {
            a[i][p[x]] = 0;
            a[p[x]][i] = 0;
            x = p[x];
        }
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n-1 ; j++)
            if(a[i][j] == 1)
                for(k=j+1 ; k<=n ; k++)
                    if(a[i][k] == 1 && a[j][k] == 1 && d[i][k]<d[i][j]+v[k])
                        d[i][k] = d[i][j]+v[k], path[i][k] = j;


    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(d[i][j]>mx)
                mx = d[i][j], x = i, y = j;

    while(y!=0)
    {
        cnt++;
        apath[cnt] = y;
        y = path[x][y];
    }
    printf("%d\n%d\n", mx, cnt);
    for(i=cnt ; i>=1 ; i--)
        printf("%d ", apath[i]);
}
