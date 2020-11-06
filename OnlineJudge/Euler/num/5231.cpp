#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pp;
vector<vector<pp> > a;
priority_queue<pp, vector<pp>, greater<pp> > Q;
priority_queue<int> dist[801];

int pn, n, m, sum;
int visit[801];

int main()
{
    int i, len;
    int x, y, z;
    pp tt;

    scanf("%d %d %d", &pn, &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, z));
    }

    Q.push(make_pair(1, 0));
    while (!Q.empty())
    {
        int here = Q.top().first;
        int cost = Q.top().second;

        Q.pop();
        len = a[here].size();

        if(dist[here].size()>pn)
            continue;

        for(i=0 ; i<len ; i++)
        {
            int next = a[here][i].first;
            int nextCost = a[here][i].second;

            if (dist[next].size() < pn)
            {
                dist[next].push(nextCost + cost);
                Q.push(make_pair(next, nextCost + cost));
            }
            else if (dist[next].top() > nextCost + cost)
            {
                dist[next].pop();
                dist[next].push(nextCost + cost);
                Q.push(make_pair(next, nextCost + cost));
            }

        }
    }

    while(!dist[n].empty())
    {
        sum+=dist[n].top();
        dist[n].pop();
    }
    printf("%d", sum);
    return 0;
}
