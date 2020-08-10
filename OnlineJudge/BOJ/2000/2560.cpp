#include <stdio.h>
#define MOD 1000

int d[1000001], sum[1000001];
int a, b, c, n;

int main()
{
    int i, j;

    scanf("%d %d %d %d", &a, &b, &c, &n);
    sum[0] = 0;

    for(i=0 ; i<a ; i++)
        d[i] = 1, sum[i] = sum[i-1]+d[i];

    for(i=a ; i<=n ; i++)
    {
        
    }
}
