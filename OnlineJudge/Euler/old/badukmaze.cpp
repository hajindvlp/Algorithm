#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pp;

int n, m;
vector<vector<pp> > a;
int visit[1010], dist[1010];
int sy, sx, ex, ey;
pp p[1010], tmp;
priority_queue<pp, vector<pp>, greater<pp> > pQ;

int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

int main()
{
    int i, j;
    int x, y, len;

    scanf("%d %d", &n, &m);
    for(i=2 ; i<=m+1 ; i++)
        scanf("%d %d", &x, &y), p[i] = make_pair(x, y);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    p[1] = make_pair(sy, sx);
    p[m+2] = make_pair(ey, ex);

    a.resize(m+3);

    for(i=1 ; i<=m+1 ; i++)
        for(j=i+1 ; j<=m+2 ; j++)
        {
            if(p[i].first == p[j].first)
            {
                a[i].push_back(make_pair(j, abs(p[i].second-p[j].second)));
                a[j].push_back(make_pair(i, abs(p[i].second-p[j].second)));
                //printf("%d %d %d %d\n", i, j, p[i].first, abs(p[i].second-p[j].second));
            }
            else if(p[i].second == p[j].second)
            {
                a[i].push_back(make_pair(j, abs(p[i].first-p[j].first)));
                a[j].push_back(make_pair(i, abs(p[i].first-p[j].first)));
                //printf("%d %d %d %d\n", i, j, p[i].second, abs(p[i].first-p[j].first));
            }
        }

    for(i=1 ; i<=m+2 ; i++)
        dist[i] = INF;

    visit[1] = 0;
    dist[1] = 0;
    pQ.push(make_pair(0, 1));
    while(!pQ.empty())
    {
        tmp = pQ.top();
        pQ.pop();
        int here = tmp.second;
        if(visit[here] == 0)
        {
            visit[here] = 1;
            len = a[here].size();
            for(i=0 ; i<len ; i++)
            {
                if(dist[a[here][i].first] > dist[here] + a[here][i].second && visit[a[here][i].first] == 0)
                {
                    dist[a[here][i].first] = dist[here] + a[here][i].second;
                    pQ.push(make_pair(dist[a[here][i].first], a[here][i].first));
                }
            }
        }
    }

    printf("%d", dist[m+2]);
    return 0;
}
