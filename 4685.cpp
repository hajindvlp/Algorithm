#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;

int a[1001][1001], v;
int n, m, dist[1001], visit[1001], path[1001], apath[1001], len;
int s, e;
char code[1001][33];

int main()
{
    int i, j, k, mn, cnt;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &code[i][1]);
        for(j=1 ; j<i ; j++)
        {
            cnt = 0;
            for(k=1 ; k<=m ; k++)
                if(code[i][k]!=code[j][k])
                    cnt++;
            if(cnt == 1)
                a[i][j] = a[j][i] = 1;
        }
    }
    scanf("%d %d", &s, &e);

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[s] = 0;

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(visit[j] == 0 && dist[j]<mn)
                mn = dist[j], v = j;
        visit[v] = 1;
        for(j=1 ; j<=n ; j++)
            if(a[v][j] == 1 && visit[j] == 0 && dist[j]>dist[v]+a[v][j])
                dist[j] = dist[v] + a[v][j], path[j] = v;
    }

    if(dist[e] >= INF)
        printf("-1");
    else
    {
        while(e != s)
        {
            len++;
            apath[len] = e;
            e = path[e];
        }
        printf("%d ", s);
        for(i=len ; i>=1 ; i--)
            printf("%d ", apath[i]);

    }
}
