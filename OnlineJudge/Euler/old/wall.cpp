#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define INF 1000000000
using namespace std;

vector<vector<int> > a;
queue<int> Q;
int n, h;
int m[10005][3], d[10005];

int main()
{
    int i, j;
    int yy, ty;
    int len;

    scanf("%d %d", &h, &n);
    a.resize(n+2);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &m[i][1], &m[i][2]);
        if(h-m[i][2]<=1000)
            a[i].push_back(n+1);
        if(m[i][2]<=1000)
            a[0].push_back(i);
        for(j=1 ; j<=i-1 ; j++)
            if(sqrt((double)pow(m[i][1]-m[j][1], 2)+(double)pow(m[i][2]-m[j][2], 2))<=1000)
                a[i].push_back(j), a[j].push_back(i);
    }

    for(i=0 ; i<=n+1 ; i++)
        d[i] = INF;

    Q.push(0);
    d[0] = 0;
    while(!Q.empty())
    {
        yy = Q.front();
        Q.pop();
        len = a[yy].size();
        for(i=0 ; i<len ; i++)
        {
            ty = a[yy][i];
            if(d[ty]>d[yy]+1)
                d[ty] = d[yy]+1, Q.push(ty);
        }
    }

    printf("%d", d[n+1]-1);
    return 0;
}
