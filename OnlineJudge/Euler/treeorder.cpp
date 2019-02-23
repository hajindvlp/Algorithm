#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> a[1001];
queue<int> Q;
int n;

void pre(int v)
{
    if(v != 0)
    {
        printf("%d ", v);
        pre(a[v].first);
        pre(a[v].second);
    }
}

void in(int v)
{
    if(v!=0)
    {
        in(a[v].first);
        printf("%d ", v);
        in(a[v].second);
    }
} 

void post(int v)
{
    if(v!=0)
    {
        post(a[v].first);
        post(a[v].second);
        printf("%d ", v);
    }
}

void level(int v)
{
    int x;

    Q.push(v);
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        if(x!=0)
        {
            printf("%d ", x);
            Q.push(a[x].first);
            Q.push(a[x].second);
        }
        
    }
}

int main()
{
    int i;
    int x, y, z;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d %d", &x, &y, &z), a[x] = make_pair(y, z);

    pre(1);
    printf("\n");
    in(1);
    printf("\n");
    post(1);
    printf("\n");
    level(1);
    return 0;
}