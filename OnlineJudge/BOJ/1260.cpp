#include <stdio.h>
#include <queue>
using namespace std;

int n ,m, v;
int a[1001][1001], visit[1001];
queue<int> Q;

void dfs(int xx)
{
    int  i;

    printf("%d ", xx);
    visit[xx] = 1;
    for(i=1; i<=n ; i++)
        if(a[xx][i] == 1 && visit[i]!=1)
            dfs(i);
}

int main()
{
    int i, x, y, xx;

    scanf("%d %d %d", &n, &m, &v);
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;

    dfs(v);
    printf("\n");
    for(i=1 ; i<=n ; i++)
        visit[i] = 0;

    Q.push(v);
    while(!Q.empty())
    {
        xx = Q.front(), Q.pop();
        if(visit[xx]!=1)
        {
            printf("%d ", xx);
            visit[xx] = 1;
            for(i=1 ; i<=n ; i++)
                if(visit[i]!=1 && a[xx][i] == 1)
                    Q.push(i);
        }
    }
    return 0;
}
