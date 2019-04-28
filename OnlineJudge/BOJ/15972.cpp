#include <stdio.h>

int n, m, h;
int a[1001][1001], d[1000001], visit[1000001], sum;

void dfs(int y, int dist)
{
    int i;
    if(d[y]>dist)
    {
        d[y] = dist;
        for(i=1 ; i<=n*m ; i++)
            if(a[y][i]!=0 && visit[i]!=1)
            {
                visit[i] = 1;
                dfs(i, (a[y][i]>dist)?a[y][i]:dist);
                visit[i] = 0;
            }
    }
}

int main()
{
    int i, j, x, y, dist;

    scanf("%d %d %d", &n, &m, &h);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d", &x);
        if(x!=-1) a[i][0] = a[0][i] = x;
    }
    for(i=1 ; i<=n-1 ; i++)
        for(j=1 ; j<=m ; j++)
        {
            scanf("%d", &x);
            if(x!=-1) a[(i-1)*m+j][i*m+j] = a[i*m+j][(i-1)*m+j] = x;
        }
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d", &x);
        if(x!=-1) a[(n-1)*m+i][0] = a[0][(n-1)*m+i] = x;
    }

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &x);
        if(x!=-1) a[0][(i-1)*m+1] = a[(i-1)*m+1][0] = x;
        for(j=1 ; j<=m-1 ; j++)
        {
            scanf("%d", &x);
            if(x!=-1) a[(i-1)*m+j][(i-1)*m+j+1] = a[(i-1)*m+j+1][(i-1)*m+j] = x;
        }
        scanf("%d", &x);
        if(x!=-1) a[0][i*m] = a[i*m][0] = x;
    }

    for(i=0 ; i<=n*m ; i++)
        d[i] = h;

    dfs(0, 0);

    for(i=1 ; i<=m*n ; i++)
        sum+=d[i];
    printf("%d", sum);
    return 0;
}
