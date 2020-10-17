#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pp;
vector<vector<pp> > a;
priority_queue<pp, vector<pp>, greater<pp> > Q;
int n, m;
int dist[50001], visit[50001];
pp tp;

int main()
{
    int i, len;
    int x, y, z;

    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y ,&z);
        a[x].push_back(make_pair(z, y));
        a[y].push_back(make_pair(z, x));
    }

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[1] = 0;

    Q.push(make_pair(0, 1));
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
    printf("%d", dist[n]);
    return 0;
}
