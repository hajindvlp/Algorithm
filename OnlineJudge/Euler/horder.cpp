#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

queue<int> Q;
int n, m, s[501], b[501], cnt;
bool visit[501];
vector<vector<int> > a;

void bfs(int sx)
{
    int xx, tx, sum = 0;
    int i, len;

    Q.push(sx);
    while(!Q.empty())
    {
        xx = Q.front(), Q.pop();
        b[sx]++;
        len = a[xx].size();
        for(i=0 ; i<len ; i++)
        {
            tx = a[xx][i];
            if(!visit[tx])
                visit[tx]=1, Q.push(tx), s[tx]++;
        }
    }
}

int main()
{
    int i, j;
    int x, y;

    scanf("%d %d", &n, &m);
    a.resize(n+1);

    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x].push_back(y);

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
            visit[j] = 0;
        visit[i] = 1;
        bfs(i);
    }

    for(i=1 ; i<=n ; i++)
        if(b[i]+s[i] == n)
            cnt++;
    printf("%d", cnt);
    return 0;
}
