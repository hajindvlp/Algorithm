#include <stdio.h>
#include <string.h>

int n, a[35][35];
int dy[2] = {0, 1}, dx[2] = {1, 0};
int ty, tx;
long long int d[35][35];

int main()
{
    int i, j, k;
    char tmp[35];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=n ; j++)
            a[i][j] = tmp[j]-'0';
    }

    d[1][1] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            for(k=0 ; k<=1 ; k++)
            {
                ty = i+dy[k]*a[i][j];
                tx = j+dx[k]*a[i][j];
                if(ty>0 && ty<=n && tx>0 && tx<=n && a[i][j]!=0)
                    d[ty][tx]+=d[i][j];
            }
    printf("%lld", d[n][n]);
    return 0;
}
