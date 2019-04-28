#include <stdio.h>
#define N 1005
#define INF 1000000000

int a[N][N], n;
int r[N][N], l[N][N], u[N][N], d[N][N];

int mx(int a, int b)
{
    if(a<b)
        return b;
    return a;
}

int main()
{
    int k, i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);
    for(i=0 ; i<=n+1 ; i++) for(j=0 ; j<=n+1 ; j++) r[i][j] = u[i][j] = l[i][j] = -INF;

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            if(i!=1)
                u[i][j] = a[i][j]+d[i-1][j];
            if(j == 1)
                l[i][j] = a[i][j]+d[i-1][j];
            else
                l[i][j] = a[i][j]+mx(l[i][j-1], a[i][j-1]+d[i-1][j-1]);
        }

        if(i!=1 && i!=n)
            for(j=n ; j>=1 ; j--)
            {
                if(j == n)
                    r[i][j] = a[i][j]+d[i-1][j];
                else
                    r[i][j] = a[i][j]+mx(r[i][j+1], a[i][j+1]+d[i-1][j+1]);
            }

        for(j=1 ; j<=n ; j++)
            d[i][j] = mx(r[i][j], mx(u[i][j], l[i][j]));
    }
    //
    // for(i=1 ; i<=n ; i++)
    // {
    //     for(j=1 ; j<=n ; j++)
    //         printf("%d ", d[i][j]);
    //     printf("\n");
    // }

    printf("%d", d[n][n]);
    return 0;
}
