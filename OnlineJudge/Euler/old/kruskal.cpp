#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, pair<int, int> > v[51];
pair<pair<int, int>, int> ans[51];
int n, m, cnt, acnt, root[51], sum;

void setroot(int x, int y)
{
    int i;

    for(i=1 ; i<=n ; i++)
        if(root[i] == x)
            root[i] = y;
}

int main()
{
    int i;
    int x, y, z;

    scanf("%d %d", &n ,&m);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        if(y>x)
            v[i] = make_pair(z, make_pair(x, y));
        else
            v[i] = make_pair(z, make_pair(y, x));
    }

    sort(v+1, v+m+1);
    for(i=1 ; i<=m ; i++)
        if(root[v[i].second.first]!=root[v[i].second.second] || root[v[i].second.first] == 0 || root[v[i].second.second] == 0)
        {
            if(root[v[i].second.first] == 0 && root[v[i].second.second] == 0)
                root[v[i].second.first] = root[v[i].second.second] = v[i].second.first;
            else if(root[v[i].second.first] != 0 && root[v[i].second.second] == 0)
                root[v[i].second.second] = root[v[i].second.first];
            else if(root[v[i].second.first] == 0 && root[v[i].second.second] != 0)
                root[v[i].second.first] = root[v[i].second.second];
            else
                setroot(root[v[i].second.first], root[v[i].second.second]);
            acnt++;
            ans[acnt] = make_pair(make_pair(v[i].second.first, v[i].second.second), v[i].first);
            sum+=v[i].first;
        }

    printf("%d\n", sum);
    //sort(ans+1, ans+acnt+1);
    //for(i=1 ; i<=acnt ; i++)
      //  printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
    return 0;
}
