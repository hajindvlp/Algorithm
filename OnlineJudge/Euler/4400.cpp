#include <stdio.h>

int n, m;
__int128 d[105];

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    d[0] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(i-j>=0)
                d[i]+=d[i-j];

    for(i=1 ; i<=100 ; i++)
        printf("%.0lf ", d[i]);

    printf("%.0lf", d[n]);
}
