#include <stdio.h>
#include <queue>
using namespace std;

void pro()
{
    queue<int> Q;
    int n, m, k, cnt = 0;
    int i, j, l, x, y;
    int a[51][51];
    int yy, xx, ty, tx;
    int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

    scanf("%d %d %d", &n, &m, &k);

    for(i=0 ; i<n ; i++)
        for(j=0 ; j<m ; j++)
            a[i][j] = 0;

    for(i=1 ; i<=k ; i++)
        scanf("%d %d", &x, &y), a[x][y] = 1;

    for(i=0 ; i<n ; i++)
        for(j=0 ; j<m ; j++)
            if(a[i][j] == 1)
            {
                cnt++;
                Q.push(i);
                Q.push(j);
                a[i][j] = 0;
                while(!Q.empty())
                {
                    yy = Q.front(), Q.pop();
                    xx = Q.front(), Q.pop();
                    for(l=0 ; l<4 ; l++)
                    {
                        ty = yy+dy[l];
                        tx = xx+dx[l];
                        if(ty>=0 && ty<n && tx>=0 && tx<m && a[ty][tx] == 1)
                        {
                            Q.push(ty);
                            Q.push(tx);
                            a[ty][tx] = 0;
                        }
                    }
                }
            }
    printf("%d\n", cnt);
}

int main()
{
    int i, n;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        pro();
}
