#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 100000000
using namespace std;

typedef pair<int, int> pp;

vector<vector<pp> > a;
priority_queue<pp, vector<pp>, greater<pp> > Q;
pp tp;

int m, n;
int dist[501], check[501], visit[501];

int dikstra(int sx)
{
    int i, len, mx = 0;

    Q.push(make_pair(0, sx));
    for(i=1 ; i<=n ; i++)
        if(check[i])
            Q.push(make_pair(0, i));
    while(!Q.empty())
    {
        tp = Q.top();
        Q.pop();
        if(visit[tp.second] == 0)
        {
            visit[tp.second] = 1;
            dist[tp.second] = tp.first;
            len = a[tp.second].size();
            for(i=0 ; i<len ; i++)
                if(visit[a[tp.second][i].second] == 0)
                    Q.push(make_pair(tp.first+a[tp.second][i].first, a[tp.second][i].second));
        }
    }
    for(i=1 ; i<=n ; i++)
        if(dist[i]>mx)
            mx = dist[i];
    return mx;
}

int main()
{
    int i, j;
    int x, y, z;
    int k, ans, mn = INF;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &x), check[x] = 1;

    a.resize(n+1);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d %d", &x, &y, &z), a[x].push_back(make_pair(z, y)), a[y].push_back(make_pair(z, x));

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
            dist[j] = INF, visit[j] = 0;
        dist[i] = 0;
        for(j=1 ; j<=n ; j++)
            if(check[j])
                dist[j] = 0;
        while(!Q.empty())
            Q.pop();
        k = dikstra(i);
        if(mn>k)
            ans = i, mn = k;
    }
    printf("%d", ans);
    return 0;
}
