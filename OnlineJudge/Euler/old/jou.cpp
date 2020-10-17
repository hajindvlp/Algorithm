#include <stdio.h>
#include <vector>
#define INF 1000000000
using namespace std;

vector<vector<pair<int, int> > > a;
int n, m;
int jou[50001], visit[50001];
int s, mn = INF;

void dfs(int x, int sum)
{
    int i, len;
    for(i=1 ; i<=m ; i++)
        if(visit[jou[i]] == 0)
            break;
            
    if(i == m+1)
    {
        if(sum<mn)
            mn = sum;
    }
    else
    {
        len = a[x].size();
        for(i=1 ; i<=len ; i++)
        {
            visit[a[x][i].second]++;
            dfs(a[x][i].second, sum+a[x][i].first);
            visit[a[x][i].second]--;
        }
    }
    
}

int main()
{
    int i;
    int x, y, z;
    scanf("%d %d", &n, &s);
    a.resize(n+1);
    for(i=1 ; i<=n-1 ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(make_pair(z, y));
        a[y].push_back(make_pair(z, x));
    }
    scanf("%d", &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &jou[i]);

    dfs(s, 0);
    printf("%d", mn);
}