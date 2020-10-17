#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pp;

priority_queue<vector<pp>, vector<pp>, greater<pp> > Q;
vector<vector<pp> > a;
int n, m;
int dist[200001], visit[200001];

int main()
{
    int i, x, y, z, len, ans, mx = 0, cnt = 0;
    pp tmp;

    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d", &x, &y);
        a[x].push_back(make_pair(y, 1));
        a[y].push_back(make_pair(x, 1));
    }
    for(i=1 ; i<=n ; i++)
        dist[i] = INF;

    Q.push(make_pair(0, 1));
    while(!Q.empty())
    {
        tmp = Q.top();
        Q.pop();
        if(!visit[tmp.second])
        {
            visit[tmp.second] = 1;
            dist[tmp.second] = tmp.first;
            len = a[tmp.second].size();
            for(i=0 ; i<len ; i++)
                if(!visit[a[tmp.second][i].first] && dist[a[tmp.second][i].first]>a[tmp.second][i].second+dist[tmp.second])
                    Q.push(make_pair(a[tmp.second][i].second+dist[tmp.second], a[tmp.second][i].first));
        }
    }
    for(i=1 ; i<=n ; i++)
        if(dist[i]>mx)
            ans = i, mx = dist[i];
    for(i=1 ; i<=n ; i++)
        if(dist[i] == mx)
            cnt++;
    printf("%d %d %d", ans, mx, cnt);

    return 0;
}
