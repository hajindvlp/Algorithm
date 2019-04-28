#include <stdio.h>
#define MOD 131

int d[4][20000001];
int n;

int main()
{
    int i;

    scanf("%d", &n), n--;
    d[1][0] = d[2][0] = d[3][0] = 1;
    for(i=1 ; i<=n ; i++)
    {
        d[1][i] += d[1][i-1]+d[2][i-1]+d[3][i-1];
        d[1][i] %= MOD;
        d[2][i] += d[1][i-1]+d[2][i-1];
        d[2][i] %= MOD;
        d[3][i] += d[1][i-1]+d[3][i-1];
        d[3][i] %= MOD;
    }
    printf("%d", (d[1][n]+d[2][n]+d[3][n])%MOD);
}
