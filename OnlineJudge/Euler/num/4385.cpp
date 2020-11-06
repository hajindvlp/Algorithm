#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > v;

int main()
{
    int i, x;

    scanf("%d", &n);
    v.resize(n+1);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &x), v[i] = make_pair(x, i);

    sort(v.begin(), v.end());

    vector<bool> vis(n+1, false);

    int ans = 0;

    for(i=1 ; i<=n ; i++)
    {
        if(vis[i] || v[i].second == i)
            continue;

        int cys = 0;
        int j = i;

        while(!vis[j])
        {
            vis[j] = 1;
            j = v[j].second;
            cys++;
        }

        if(cys>0)
            ans+=cys-1;
    }

    printf("%d", ans);
    return 0;
}
