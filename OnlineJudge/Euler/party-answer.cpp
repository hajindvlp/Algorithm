#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[101][101], v[101], path[101][101], cnt[101];

pair<int, int> rec(int x, int lev)
{
    int i, s = 0, j;
    pair<int, int> p, lp;

    p = make_pair(v[x], 0);

    for(i=1 ; i<=a[x][0] ; i++)
    {
        lp = rec(a[x][i], lev+1);
        p.first  += lp.second;
        if(lp.first>lp.second)
            s+=lp.first, path[x][++cnt[x]] = a[x][i];
        else
        {
            s+=lp.second;
            for(j=1 ; j<=cnt[a[x][i]] ; j++)
                path[x][++cnt[x]] = path[a[x][i]][j];
        }
    }
    if(p.second<s)
        p.second = s;
    return p;
}

int main()
{
    int i, j, k;
    int x, y, z;
    pair<int, int> ans;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        a[y][++a[y][0]] = x;
        v[x] = z;
    }
    ans = rec(1, 1);
    printf("%d\n%d\n", (ans.first>ans.second)?ans.first:ans.second, cnt[1]);
    for(i=1 ; i<=cnt[1] ; i++)
        printf("%d ", path[1][i]);
    return 0;
}
