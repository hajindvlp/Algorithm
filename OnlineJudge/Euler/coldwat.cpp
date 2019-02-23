#include <stdio.h>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

vector<vector<int> > a;
queue<int> Q;
int n, m;
int d[100000];

int main()
{
    int i;
    int x, y, z;
    int len;

    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[x].push_back(y);
        a[x].push_back(z);
    }
    for(i=1 ; i<=n ; i++)
        d[i] = INF;

    Q.push(1);
    d[1] = 1;
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        len = a[x].size();
        for(i=0 ; i<len ; i++)
            if(d[x]+1<d[a[x][i]])
            {
                d[a[x][i]] = d[x]+1;
                Q.push(a[x][i]);
            }
    }

    for(i=1 ; i<=n ; i++)
        printf("%d\n", d[i]);
    return 0;
}
