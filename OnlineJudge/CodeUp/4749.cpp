#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int> > Q;
vector<vector<int> > a;
pair<int, int> yy;
int n;
int esum, len;

int main()
{
    int i, x, y;

    scanf("%d", &n);
    a.resize(n+1);
    for(i=1 ; i<=n-1 ; i++)
    {
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
    }

    Q.push({1, 1});
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        len = a[yy.first].size();
        esum+=yy.second%2;
        for(i=0 ; i<len ; i++)
            Q.push({a[yy.first][i], yy.second+1});
    }
    printf("%d", esum);
}
