#include <stdio.h>
using namespace std;

int a[101][101], sum[101][101], d[101][101], n;
int asum = -1000000000;

int findmx(int y, int x)
{
    int mx = 0;
    int i, j;

    for(i=1 ; i<=y ; i++)
        for(j=1 ; j<=x ; j++)
            if(sum[y][x]-sum[i-1][x]-sum[y][j-1]+sum[i-1][j-1]>mx)
                mx = sum[y][x]-sum[i-1][x]-sum[y][j-1]+sum[i-1][j-1];

    return mx;
}

int main()
{
    int i, j, tmp;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]), sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
        {
            tmp = findmx(i, j);
            if(tmp>asum)
                asum = tmp;
        }

    printf("%d", asum);
    return 0;
}
