#include <stdio.h>
#define MOD 123456789

int n, m, d[5001];

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    d[0] = 1;
    for(i=1 ; i<=m ; i++)
        for(j=i ; j<=n ; j++)
            d[j]=(d[j]+d[j-i])%MOD;

    printf("%d", d[n]);
    return 0;
}
