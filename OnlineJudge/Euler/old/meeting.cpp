#include <stdio.h>
#include <queue>
#define INF 100000

using namespace std;

queue<int> Q;
int n, m;
int groupsum[101], dist[101], group[101], top[101], groupcnt;
bool a[101][101], visit[101];

void bfs(int sx)
{
    int x, sum = 0, i;

    visit[sx] = 1;
    if(group[sx] == 0)
    {
        groupcnt++;
    }
    Q.push(sx);
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        if(group[x] == 0)
            group[x] = sx;
        for(i=1 ; i<=n ; i++)
        {
            if(a[x][i] && visit[i] == 0)
            {
                visit[i] = true;
                dist[i] = dist[x]+1;
                Q.push(i);
            }
        }
    }
    for(i=1 ; i<=n ; i++)
    {
        if(dist[i]>sum)
            sum = dist[i];
        dist[i] = 0;
        visit[i] = 0;
    }
    if(groupsum[group[sx]]>sum)
    {
        groupsum[group[sx]] = sum;
        top[group[sx]] = sx;
    }
}

int main()
{
    int i, x, y;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y] = true;
        a[y][x] = true;
    }

    for(i=1 ; i<=n ; i++)
    {
        groupsum[i] = INF;

        bfs(i);
    }

    printf("%d\n", groupcnt);
    for(i=1 ; i<=n ; i++)
        if(top[i]!=0)
            printf("%d\n", top[i]);
    return 0;
}
