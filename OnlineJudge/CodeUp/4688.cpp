#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pp;

map<int, int> hm;
priority_queue<pp,  vector<pp>, greater<pp> > Q;
vector<vector<int> > a;
int n, m, en, apath[100001], e;
int dist[100001], path[100001];
int code[100001];
pp xx;

int main()
{
    int i, j;
    int sum = 0, tmp[32], len;
    int ap;

    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=n ; i++)
    {
        sum = 0;
        for(j=1 ; j<=m ; j++)
            scanf("%1d", &tmp[j]), sum+=tmp[j]*(1<<(m-j));
        hm[sum] = i;
        code[i] = sum;
    }

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(hm.count(code[i]|(1<<(j-1))) == 1 && i != hm[code[i]|(1<<(j-1))])
            {
                a[i].push_back(hm[code[i]|(1<<(j-1))]);
                a[hm[code[i]|(1<<(j-1))]].push_back(i);
            }

    Q.push(make_pair(0, 1));
    while(!Q.empty())
    {
        xx = Q.top();
        Q.pop();
        if(dist[xx.second]>xx.first)
        {
            dist[xx.second] = xx.first;
            len = a[xx.second].size();
            for(i=0 ; i<len ; i++)
                if(dist[a[xx.second][i]]>dist[xx.second]+1)
                    Q.push(make_pair(dist[xx.second]+1, a[xx.second][i])), path[a[xx.second][i]] = xx.second;
        }
    }

    scanf("%d", &en);
    for(i=1 ; i<=en ; i++)
    {
        scanf("%d", &e);
        len = 0;
        ap = e;
        while(ap!=1)
        {
            if(ap >= INF || apath[ap] >= INF || ap == 0)
            {
                printf("-1\n");
                break;
            }
            apath[++len] = ap;
            ap = path[ap];
        }
        if(ap == 1)
        {
            apath[++len] = 1;

            for(j=len ; j>=1 ; j--)
                printf("%d ", apath[j]);
            printf("\n");
        }
    }
    return 0;
}
