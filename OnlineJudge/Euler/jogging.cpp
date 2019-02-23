#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pp;

priority_queue<pp, vector<pp>, greater<pp> > Q;
pp tp;

int n, m, k, sum;
int a[1001][1001], visit[1001], dist[1001][101];

int main()
{
    int i;
    int x, y, z;

    scanf("%d %d %d", &k, &n, &m);

    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x][y] = a[y][x] = z;
    }

    Q.push(make_pair(0, 1));
    while(!Q.empty())
    {
        tp = Q.top();
        Q.pop();
        if(visit[tp.second]<k)
        {
            visit[tp.second]++;
            dist[tp.second][visit[tp.second]] = tp.first;
            for(i=1 ; i<=n ; i++)
                if(visit[i]<k && a[i][tp.second]!=0)
                    Q.push(make_pair(a[i][tp.second]+tp.first, i));
        }
    }
    for(i=1 ; i<=k ; i++)
        sum+=dist[n][i];
    printf("%d", sum);

    return 0;
}
