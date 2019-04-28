#include <stdio.h>

int d[1000001], n;

int main()
{
    int i;

    scanf("%d", &n);
    d[0] = d[1] = 1;
    for(i=2 ; i<=n ; i++)
        d[i] = (d[i-1]+d[i-2])%15746;
    printf("%d", d[n]%15746);
    return 0;
}
