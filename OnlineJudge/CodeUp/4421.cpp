#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, a[27][27], visit[26][26], ans[128], cnt;
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
queue<int> Q;

int main()
{
    int i, j, k;
    int yy, xx, ty, tx;
    char tmp[29];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=n ; j++)
            a[i][j] = tmp[j]-'0';
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(a[i][j] == 1)
            {
                cnt++;
                Q.push(i), Q.push(j);
                a[i][j] = 0;
                while(!Q.empty())
                {
                    yy = Q.front(), Q.pop();
                    xx = Q.front(), Q.pop();
                    ans[cnt]++;
                    for(k=0 ; k<4 ; k++)
                    {
                        ty = yy+dy[k];
                        tx = xx+dx[k];
                        if(ty>0 && ty<=n && tx>0 && tx<=n && a[ty][tx] == 1)
                            Q.push(ty), Q.push(tx), a[ty][tx] = 0;
                    }
                }
            }

    sort(ans+1, ans+cnt+1);
    printf("%d\n", cnt);
    for(i=1 ; i<=cnt ; i++)
        printf("%d\n", ans[i]);

    return 0;
}
