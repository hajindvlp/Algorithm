#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;

pair<int, int> d[12001];
int n, dist[101], cost[101];
int e;

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &dist[i], &cost[i]);
    e = dist[n];

    for(i=1 ; i<=100 ; i++)
        d[i] = make_pair(0, 100-i);

    for(i=0 ; i<=n ; i++)
    {
        for(j=dist[i] ; j<=e ; j++)
            if(d[j].first)
    }
}
