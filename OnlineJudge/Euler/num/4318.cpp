#include <stdio.h>
#define INF 1000000000

int n, c, a[1001][1001], d[1001][1001];

int main()
{
    int i, j, mn;

    scanf("%d %d", &c, &n);
    for(i=1 ; i<=n ; i++)
        for(j=i ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=i-1 ; j++)
            if(d[j][i-1]<mn)
                mn = d[j][i-1];

        if(i==1)
            for(j=i ; j<=n ; j++)
                d[i][j] = c+a[i][j];
        else
            for(j=i ; j<=n ; j++)
                d[i][j] = mn+c+a[i][j];
    }

    mn = INF;
    for(i=1 ; i<=n ; i++)
        if(d[i][n]<mn)
            mn = d[i][n];

    printf("%d", mn);
    return 0;
}
