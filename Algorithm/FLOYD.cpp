#include <stdio.h>
#define INF 1000000000

int n, a[101][101], dist[101][101];

int main()
{
    int i, j, k;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            dist[i][j] = INF;

    for(k=1 ; k<=n ; k++)
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j] = dist[i][k]+dist[k][i];
}
