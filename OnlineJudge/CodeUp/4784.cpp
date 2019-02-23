#include <stdio.h>

int w[101], v[101], n, m;
int d[101][10001], f;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &w[i]);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &v[i]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=10000 ; j++)
        {
            d[i][j] = d[i-1][j];
            if(j>=v[i] && d[i][j]<d[i-1][j-v[i]]+w[i])
                d[i][j] = d[i-1][j-v[i]]+w[i];
        }

    for(i=1 ; i<=10000 ; i++)
        if(d[n][i]>=m)
        {
            printf("%d", i);
            return 0;
        }
}
