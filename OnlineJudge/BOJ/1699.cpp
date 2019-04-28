#include <stdio.h>
#define INF 1000000000

int n, d[100001];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        d[i] = INF;

    for(i=1 ; i*i<=n ; i++)
        for(j=i*i ; j<=n ; j++)
            if(d[j]>d[j-i*i]+1)
                d[j] = d[j-i*i]+1;

    printf("%d", d[n]);
}
