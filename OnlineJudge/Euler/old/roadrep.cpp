#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > v;
int n, path[1045], visit[501][501];
bool k = false ;

bool dfs(int r, int lev)
{
    int i, len;

    path[lev] = r;

    if(lev == n+1 && !k)
    {
        for(i=1 ; i<=lev ; i++)
            printf("%d\n", path[i]);
        k = true;
    }
    else if(lev<n+1)
    {
        len = v[r].size();
        for(i=0 ; i<len ; i++)
            if(visit[r][v[r][i]] == 1)
            {
                visit[r][v[r][i]] = visit[v[r][i]][r] = 0;
                dfs(v[r][i], lev+1);
                visit[r][v[r][i]] = visit[v[r][i]][r] = 1;
            }
    }
}

int main()
{
    int i, x, y, s=0;

    scanf("%d", &n);
    v.resize(n+1);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
        visit[x][y] = 1;
        visit[y][x] = 1;

        if(x>s)
            s = x;
        if(y>s)
            s = y;
    }

    for(i=1 ; i<=s ; i++)
        if(dfs(i, 1))
            break;
    return 0;
}
