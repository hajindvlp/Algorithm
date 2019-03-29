#include <stdio.h>

int n, m, a[10001], d[10001];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n ; i++)
    {
        for(j=i ; j<=n ; j++)
            if(d[j]<d[j-i]+a[i])
                d[j] = d[j-i]+a[i];
    }
    printf("%d", d[n]);

    return 0;
}
