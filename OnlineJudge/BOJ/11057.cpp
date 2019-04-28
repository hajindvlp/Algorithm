#include <stdio.h>
#define MOD 10007

int d[10], n, sum[10], asum;

int main()
{
    int i, j;

    scanf("%d", &n);

    d[0] = sum[0] = 1;
    for(i=1 ; i<=9 ; i++)
        d[i] = 1, sum[i] = sum[i-1]+d[i];

    for(i=1 ; i<=n-1 ; i++)
    {
        d[0] = sum[0];
        for(j=1 ; j<=9 ; j++)
            d[j] = sum[j] % MOD, sum[j] = (sum[j-1]+d[j])%MOD;
    }

    for(i=0 ; i<=9 ; i++)
        asum += d[i]%MOD;
    printf("%d", asum%MOD);
}
