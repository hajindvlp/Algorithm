#include <stdio.h>

int d[41];

int main()
{
    int i, n;

    d[1] = 1;
    d[2] = 1;

    scanf("%d", &n);
    for(i=3 ; i<=n ; i++)
        d[i] = d[i-1]+d[i-2];

    printf("%d", d[n]);
    return 0;
}
