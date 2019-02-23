#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> Q;
int n, a[26][26], cnt, ans[700], visit[26][26];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
int xx, yy, ty, tx;

void bfs(int sy, int sx)
{
    int i, tmp = 0;

    cnt++;
    Q.push(sy);
    Q.push(sx);
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        tmp++;
        visit[yy][xx] =  1;
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=n && a[ty][tx] == 1 && visit[ty][tx]!=1)
            {
                visit[ty][tx] = 1;
                Q.push(ty);
                Q.push(tx);
            }
        }
    }
    ans[cnt] = tmp;
}

int main()
{
    int i, j;
    char c[26];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &c[1]);
        for(j=1 ; j<=n ; j++)
            a[i][j] = c[j]-'0';
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(visit[i][j] == 0 && a[i][j] == 1)
                bfs(i, j);

    sort(ans+1, ans+cnt+1);
    printf("%d\n", cnt);
    for(i=1 ; i<=cnt ; i++)
        printf("%d\n", ans[i]);
    return 0;
}
