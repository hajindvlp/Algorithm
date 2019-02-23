#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

queue<int> Q;
vector<vector<int> > a;
int n, m, k, cnt;
int d[1001], p[101];
bool visit[1001];

void bfs(int sx)
{
    int xx, tx;
    int i, len;

    Q.push(sx);
    while(!Q.empty())
    {
        xx = Q.front(), Q.pop();
        len = a[xx].size();
        for(i=0 ; i<len ; i++)
        {
            tx = a[xx][i];
            if(!visit[tx])
                visit[tx]=1, Q.push(tx);
        }
    }
}

int main()
{
    int i, j;
    int x, y;

    scanf("%d %d %d", &k, &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=k ; i++)
        scanf("%d", &p[i]);
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x].push_back(y);

    for(i=1 ; i<=k ; i++)
    {
        visit[p[i]] = 1;
        bfs(p[i]);
        for(j=1 ; j<=n ; j++)
            d[j]+=visit[j], visit[j] = 0;
    }

    for(i=1 ; i<=n ; i++)
        if(d[i] == k)
            cnt++;
    printf("%d", cnt);
    return 0;
}
