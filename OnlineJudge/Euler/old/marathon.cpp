#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 100000000
using namespace std;

typedef pair<int, int> pp;
priority_queue<pp, vector<pp>, greater<pp> > Q;
vector<vector<pp> > a;

int n, m;
int dist[40001], visit[40001];
pp tp;
char c;

int main()
{
    int i;
    int x, y, z, k, mx = 0, len ,tmp;

    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d %c", &x, &y, &z, &c);
        a[x].push_back(make_pair(z, y));
        a[y].push_back(make_pair(z, x));
    }

    k = 1;
    while(1)
    {
        for(i=1 ; i<=n ; i++)
            dist[i] = INF, visit[i] = 0;
        dist[k] = 0;

        Q.push(make_pair(0, k));
        while(!Q.empty())
        {
            tp = Q.top();
            Q.pop();
            if(visit[tp.second] == 0)
            {
                visit[tp.second] = 1;
                dist[tp.second] = tp.first;
                if(tp.first>mx)
                {
                    mx = tp.first;
                    k = tp.second;
                }
                len = a[tp.second].size();
                for(i=0 ; i<len ; i++)
                    if(visit[a[tp.second][i].second] == 0)
                        Q.push(make_pair(a[tp.second][i].first+tp.first, a[tp.second][i].second));
            }
        }
        if(tmp==mx)
        {
            printf("%d", mx);
            break;
        }
        else
            tmp = mx;
    }
    return 0;
}
