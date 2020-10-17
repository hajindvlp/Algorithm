#include <stdio.h>
#define N 1500

int a[N+1][N+1], sum[N+1][N+1], d[4][N*N+2*N+2];
int cnt, n, m, l, mx;

int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

int main()
{
    int i, j;

    scanf("%d %d %d", &n, &m, &l);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
        {
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
            if(i>=l && j>=l)
            {
                cnt++;
                d[1][cnt] = sum[i][j]-sum[i-l][j]-sum[i][j-l]+sum[i-l][j-l];
                d[2][cnt] = i;
                d[3][cnt] = j;
            }
        }
    for(i=1 ; i<=cnt-1 ; i++)
        for(j=i ; j<=cnt ; j++)
            if((abs(d[2][i]-d[2][j])>=l || abs(d[3][i]-d[3][j])>=l) && d[1][i]+d[1][j]>mx)
                mx = d[1][i]+d[1][j];

    printf("%d", mx);
    return 0;
}
