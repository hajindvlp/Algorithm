#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> path[301][21];
int d[301], u[301], a[21][301], apath[301];
int n, m, cnt;

int main()
{
    int i, j, k;
    int x, y;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &x);
        for(j=1 ; j<=m ; j++)
        {
            scanf("%d", &x);
            a[j][i] = x;
        }
    }

    for(i=1 ; i<=m ; i++)
    {
        for(j=1 ; j<=n ; j++)
            for(k=1 ; k<=j ; k++)
                if(d[j]<d[j-k]+a[i][k])
                    u[j] = d[j-k]+a[i][k], path[j][i] = make_pair(j-k, k);
        for(j=1 ; j<=n ; j++)
            d[j] = u[j];
    }
    printf("%d\n", d[n]);
    x = n;
    y = m;
    while(1)
    {
        apath[++cnt] = path[x][y].second;
        x = path[y][x].first;
        y--;
        if(cnt == m)
            break;
    }
    for(i=cnt ; i>=1 ; i--)
        printf("%d ", apath[i]);
}
