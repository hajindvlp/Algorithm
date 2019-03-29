#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;

int a[101][101], n, m;
int ans[101], cnt, visit[101], p[101], s[101];

int main()
{
    int i, j, k;
    int x, y, sum;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            a[i][j] = INF;
    for(i=1 ; i<=n ; i++)
        s[i] = INF;

    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;

    for(k=1 ; k<=n ; k++)
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j] = a[i][k]+a[k][j];

    for(i=1 ; i<=n ; i++)
    {
        if(p[i] == 0)
        {
            cnt++;
            for(k=1 ; k<=n ; k++)
                if(a[i][k]<INF || i==k)
                    p[k] = cnt;
        }
        sum = 0;
        for(j=1 ; j<=n ; j++)
            if(i!=j && a[i][j]<INF)
                sum+=a[i][j];
        if(s[p[i]]>sum)
            s[p[i]] = sum, ans[p[i]] = i;
    }
    
    printf("%d\n", cnt);
    for(i=1 ; i<=cnt ; i++)
        printf("%d\n", ans[i]);
}
