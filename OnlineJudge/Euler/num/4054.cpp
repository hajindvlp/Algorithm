#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> Q;
pair<int, int> ans[5001];
int n, a[16][16], visit[16][16], cnt;
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

void bfs()
{
    int i;
    int yy, xx, ty, tx;

    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        visit[yy][xx] = 1;
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=n)
            {
                if(a[ty][tx] == 2 && visit[ty][tx] == 0)
                {
                    Q.push(ty);
                    Q.push(tx);
                }
                else if(a[ty][tx] == 0)
                {
                    cnt++;
                    ans[cnt] = make_pair(tx, ty);
                    a[ty][tx] = 1;
                }
            }
        }
    }
}

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(visit[i][j]==0 && a[i][j] == 2)
            {
                Q.push(i);
                Q.push(j);
                bfs();
            }

    printf("%d\n", cnt);
    sort(ans+1, ans+cnt+1);
    for(i=1 ; i<=cnt ; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
