#include <stdio.h>
#include <queue>
using namespace std;

int n, m, q;
int a[10001][5], d[10001][5][10001][5];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
queue<int> Q;

void pro()
{
    int i, j, k, l;
    int yy, xx, ty, tx;

    for(i=1 ; i<=10000 ; i++)
        for(j=1 ; j<=3 ; j++)
            for(k=1 ; k<=10000 ; k++)
                for(l=1 ; l<=3 ; l++)
                    d[i][j][k][l] = INF;

    scanf("%d %d %d", &n, &m, &q);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
}
