#include <stdio.h>

int a[1001][1001], d[1001][1001];
int n, m, mx;

int main()
{
    int i, j;
    int x, y;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x][y] = 1;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(a[i][j]!=1)
            {
                if(i == 1 || j == 1 )
                    d[i][j] = 1;
                else if(d[i-1][j] == d[i][j-1])
                {
                    if(d[i-1][j-1] >= d[i-1][j])
                        d[i][j] = d[i-1][j]+1;
                    else
                        d[i][j] = d[i-1][j];
                }
                else
                {
                    if(d[i-1][j]<d[i][j-1])
                        d[i][j] = d[i-1][j]+1;
                    else
                        d[i][j] = d[i][j-1]+1;
                     
                }
            }
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(mx<d[i][j])
                mx = d[i][j];

    printf("%d", mx);
    return 0;
}