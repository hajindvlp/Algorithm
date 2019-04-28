#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

priority_queue<int> Q[2001];
int n, m;

int main()
{
    int i, j, k;
    int x, y, next;
    int v, ans = INF, cnt, asc = 1;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d", &x, &y);
        if(x>y)
            Q[y].push(x);
        else
            Q[x].push(y);
    }

    for(i=1 ; i<=n ; i++)
        if(!Q[i].empty())
        {
            cnt = 0;
            for(j=i ; j<=i+n-1 ; j+=asc)
                if(!Q[j].empty())
                {
                    v = Q[j].top();
                    next = 0;
                    for(k=j+1 ; k<=v ; k++)
                        if(!Q[k].empty() && Q[k].top()>v)
                        {
                            next = k;
                            break;
                        }
                    if(next == 0) cnt+=(v-j), j = v, asc = 1;
                    else cnt+=(next-j), j = next-1, asc = 1;
                }
            if(cnt<ans)
                ans = cnt;
            while(!Q[i].empty())
            {
                Q[Q[i].top()].push(i+n);
                Q[i].pop();
            }
        }

    printf("%d", ans);
    return 0;
}
