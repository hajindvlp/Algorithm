#include <stdio.h>
#define INF 1000000000

int n, a[1001], d[1001];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), d[i] = INF;
    d[1] = 0;

    for(i=1 ; i<=n ; i++)
        for(j=i ; j<=i+a[i] && j<=n ; j++)
            if(d[j]>d[i]+1)
                d[j] = d[i]+1;

    if(d[n] >= INF)
        printf("-1");
    else

        printf("%d", d[n]);
}
