#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> pp;

map<int, int> m;
priority_queue<pp, greater<pp>, vector<pp> > Q;
vector<vector<pp> > a;
int n, m;
int e[51];
int dist[100001], visit[100001], path[100001];
int code[100001];

int main()
{
    int i, j;
    int sum = 0, tmp[32];

    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for(i=1 ; i<=n ; i++)
    {
        sum = 0;
        for(j=1 ; j<=m ; j++)
            scanf("%ld", &tmp[j]), sum+=tmp[j]*(1<<(m-j));
        m[sum] = i;
        code[i] = sum;
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(code[i] != code[i]|(1<<(j-1)) && m.find(code[i]|(1<<(j-1))) != m.end())
                a[i].push_back(make_pair(m[code[i]|(1<<(j-1))], i));

    for(i=1 ; i<=n ; i++)
    {
        len = v[i].size();
        for(j=0 ; j<len ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
