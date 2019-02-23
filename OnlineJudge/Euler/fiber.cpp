#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

priority_queue<int> Q[20001];
int n, m;

int main()
{
    int i, j;
    int x, y;
    int mx, ans = INF;

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
            mx = 0;
            for(j=i+1 ; j<=i+n ; j++)
                if(!Q[j].empty() && mx<Q[j].top())
                    mx = Q[j].top();

            if(mx <= Q[i].top() && ans>Q[i].top()-i)
            {
                ans = Q[i].top()-i;
                break;
            }
            else
                while(!Q[i].empty())
                {
                    Q[Q[i].top()].push(i+n);
                    Q[i].pop();
                }
        }

    printf("%d", ans);
    return 0;
}