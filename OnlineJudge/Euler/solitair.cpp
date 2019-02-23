#include <stdio.h>

int n, a[8][8], d[8][8];
int dy[2] = {1, 0}, dx[2] = {0, -1};

int main()
{
    int i, j, k, ty, tx;
    char x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
        {
            scanf(" %c%c", &x, &y);
            if(x-'0'>1 && x-'0'<10)
                a[i][j] = x-'0';
            else if(x == 'T')
                a[i][j]  = 10;
            else if(x == 'J')
                a[i][j] = 11;
            else if(x == 'Q')
                a[i][j] = 12;
            else if(x == 'K')
                a[i][j] = 13;
            else
                a[i][j] = 1;
        }

    d[n][1] = a[n][1];
    for(i=n ; i>=1 ; i--)
        for(j=1 ; j<=n ; j++)
            for(k=0 ; k<2 ; k++)
            {
                ty = i+dy[k];
                tx = j+dx[k];
                if(ty>0 && ty<=n && tx>0 && tx<=n && d[i][j] < d[ty][tx]+a[i][j])
                    d[i][j] = d[ty][tx]+a[i][j];
            }
    printf("%d", d[1][n]);
    return 0;
}
