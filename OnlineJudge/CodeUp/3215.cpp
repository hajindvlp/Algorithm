#include <stdio.h>
#define INF 1000000000

int d[26][26], n, m, s, e;

int main()
{
    int i, j, k;
    char x, y;
    int z;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            d[i][j] = INF;

    for(i=1 ; i<=m ; i++)
    {
        scanf(" %c %c %d", &x, &y, &z);
        d[x-'A'+1][y-'A'+1] = d[y-'A'+1][x-'A'+1] = z;
    }

    scanf(" %c %c", &x, &y);
    s = x-'A'+1;
    e = y-'A'+1;

    for(k=1 ; k<=n ; k++)
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j] = d[i][k]+d[k][j], path[];

    if(d[s][e] >= INF)
        printf("-1");
    else
        printf("%d", d[s][e]);
    return 0;
}
