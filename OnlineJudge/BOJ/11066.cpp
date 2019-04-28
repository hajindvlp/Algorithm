#include <stdio.h>

void pro()
{
    int n, i;

    for(i=1 ; i<=500 ; i++)
        a[i] = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    sort(a+1, a+n+1);
    for(i=1 ; i<=n/2 ; i++)
}
