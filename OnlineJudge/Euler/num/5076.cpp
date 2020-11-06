#include <stdio.h>

int n, a[101], d[101][101], sum[101];

int mx(int x, int y)
{
    if(x>y)
        return x;
    return y;
}

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), sum[i] = sum[i-1]+a[i];

    for(i=1 ; i<=n ; i++)
        d[i][i] = a[i];

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n-i+1 ; j++)
            d[j][i+j-1] = mx(sum[i+j-1]-sum[j-1]-d[j+1][i+j-1], sum[i+j-1]-sum[j-1]-d[j][i+j-2]);
            
    printf("%d %d", d[1][n], sum[n]-d[1][n]);
    return 0;
}