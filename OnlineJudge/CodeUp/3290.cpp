#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 100000000
using namespace std;
typedef pair<int, int> pp;

int n, sum;
vector<vector<pp> > a;
int d[10005], visit[10005];
int v, mn, len, m;
int x, y, z;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, z));
    }

    for(i=1 ; i<=n ; i++)
        d[i] = INF;
    d[1] = 0;

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(!visit[j] && mn>d[j])
            {
                mn = d[j];
                v = j;
            }
        visit[v] = 1;
        
        sum += mn;
        len = a[v].size();
        for(j=0 ; j<len ; j++)
            if(a[v][j].second!=0 && d[a[v][j].first]>a[v][j].second)
                d[a[v][j].first] = a[v][j].second;
    }
    printf("%d", sum);
}
