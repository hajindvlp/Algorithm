#include <stdio.h>
#define INF 10000000000

int a[1001][1001], n, d[3][1001][1001];

int main()
{
    int k, i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]), d[i][j] = -INF;

    for(k=1 ; k<=3 ; k++)
    {

    }
}
