#include <stdio.h>
#define MOD 1000000000

int n;
int d[12], sum, tmp[12];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=0 ; i<10 ; i++)
        d[i] = 1;

    for(i=1 ; i<=n-1 ; i++)
    {
        for(j=1 ; j<=9 ; j++)
            tmp[j] = (d[j-1]+d[j+1])%MOD;
        tmp[0] = d[1];
        for(j=0 ; j<=9 ; j++)
            d[j] = tmp[j];
    }

    for(i=1 ; i<=9 ; i++)
        sum+=d[i], sum%=MOD;

    printf("%d", sum);
    return 0;
}
