#include <stdio.h>
#define INF 1000000000

int n, m, a[101], d[10001];

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    for(i=1 ; i<=m ; i++)
        d[i] = INF;

    for(i=1 ; i<=n ; i++)
        for(j=a[i] ; j<=m ; j++)
            if(d[j]>d[j-a[i]]+1)
                d[j] = d[j-a[i]]+1;

    if(d[m]>=INF)
        printf("-1");
    else
        printf("%d", d[m]);
    return 0;
}
