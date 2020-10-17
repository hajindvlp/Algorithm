#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

queue<int> Q;
int a[112][112];
int n, p, m;
int pc[11], ps[11];
int d[112];
long long int dsum[112];
int x1, x2, c, rn, len;
long long int mx = INF;

int main()
{
    int i, j;

    scanf("%d %d %d", &n, &p, &m);
    for(i=1 ; i<=p ; i++)
        scanf("%d %d", &ps[i], &pc[i]);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &c, &rn, &x1);
        for(j=2 ; j<=rn ; j++)
        {
            scanf("%d", &x2);
            a[x1][x2] = a[x2][x1] = c;
            x1 = x2;
        }
    }

    for(i=1 ; i<=p ; i++)
    {
        for(j=1 ; j<=n ; j++)
            d[j] = INF;
        d[ps[i]] = 0;
        Q.push(ps[i]);
        while(!Q.empty())
        {
            x1 = Q.front(), Q.pop();
            for(j=1 ; j<=n ; j++)
            {
                x2 = j;
                c = a[i][j];
                if(d[x2]>d[x1]+c && c!=0)
                {
                    d[x2] = d[x1]+c;
                    Q.push(x2);
                }
            }
        }
        for(j=1 ; j<=n ; j++)
            dsum[j]+=d[j]*pc[i];
    }

    for(i=1 ; i<=n ; i++)
        if(dsum[i]<mx)
            mx = dsum[i];

    for(i=1 ; i<=n ; i++)
        printf("%lld ", dsum[i]);
    if(mx == INF)
        printf("-1");
    else
        printf("%lld", mx);
    return 0;
}
