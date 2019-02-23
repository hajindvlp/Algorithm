#include <stdio.h>

int a[5], d[301], n;

int main()
{
    int i, j;

    for(i=1 ; i<=3 ; i++)
        scanf("%d", &a[i]);
    scanf("%d", &n);

    d[0] = 1;
    for(i=1 ; i<=3 ; i++)
        for(j=a[i] ; j<=n ; j++)
            d[j] += d[j-a[i]];
    printf("%d", (bool)d[n]);
    return 0;
}
