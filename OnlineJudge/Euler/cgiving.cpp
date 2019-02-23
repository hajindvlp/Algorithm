#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 10000000000
using namespace std;

typedef pair<int, int> pp;

priority_queue<pp, vector<pp>, greater<pp> > Q;
vector<vector<pp> > a;
int n, m, g, visit[50002], l, give[25002][3];
long long int dist[50002];
pp xx;

int main()
{
    int i, j;
    int x, y, z;

    scanf("%d %d %d", &n, &m, &g);
    a.resize(n+1);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(make_pair(z, y));
        a[y].push_back(make_pair(z, x));
    }
    for(i=1 ; i<=g ; i++)
        scanf("%d %d", &give[i][1], &give[i][2]);
    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[1] = 0;

    Q.push(make_pair(0, 1));
    xx = make_pair(0, 0);
    for(i=1 ; i<=n ; i++)
    {
        while(visit[xx.second] != 0)
            xx = Q.top(), Q.pop();

        visit[xx.second] = 1;
        l = a[xx.second].size();
        for(j=0 ; j<l ; j++)
            if(visit[a[xx.second][j].second]==0 && dist[a[xx.second][j].second]>dist[xx.second]+a[xx.second][j].first)
            {
                dist[a[xx.second][j].second] = dist[xx.second]+a[xx.second][j].first;
                Q.push(make_pair(dist[xx.second]+a[xx.second][j].first, a[xx.second][j].second));
            }
    }
    for(i=1 ; i<=g ; i++)
        printf("%lld\n", dist[give[i][1]]+dist[give[i][2]]);
    return 0;
}
