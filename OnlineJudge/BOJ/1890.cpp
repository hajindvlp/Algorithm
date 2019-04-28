#include <stdio.h>

int n, a[101][101];
long long int d[101][101];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    d[1][1] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(d[i][j]!=0)
            {
                if(i == n && j == n) continue;
                if(i+a[i][j]<=n)
                    d[i+a[i][j]][j]+=d[i][j];
                if(j+a[i][j]<=n)
                    d[i][j+a[i][j]]+=d[i][j];
            }

    printf("%lld", d[n][n]);
}
