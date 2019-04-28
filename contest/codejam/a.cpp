#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;
int n, m, a[6][6];
pair<int, int> path[6][6];

void init()
{
    int i, j;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            a[i][j] = 0, path[i][j] = make_pair(0, 0);
}

bool full()
{
    int i, j;

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(a[i][j]!=1)
                return false;
    return true;
}

void print(int sy, int sx, int ey, int ex)
{
    int yy, xx, ty, tx, cnt = 0, i;
    pair<int, int> apath[51];

    yy = ey, xx = ex;
    while(yy!=sy && xx!=sx)
    {
        apath[++cnt] = make_pair(yy, xx);
        ty = yy, tx = xx;
        yy = path[ty][tx].first;
        xx = path[ty][tx].second;
    }
    printf("%d", cnt);

    for(i=1 ; i<=cnt ; i++)
        printf("%d %d\n", apath[i].first, apath[i].second);
}

int main()
{
    int i, j, k, sy, sx, yy, xx, ey, ex, l, cnt;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
        {
            init();
            cnt = 0;
            sy = i, sx = j;
            Q.push(i), Q.push(j);
            while(!Q.empty())
            {
                yy = Q.front(), Q.pop();
                xx = Q.front(), Q.pop();
                ey = yy;
                ex = xx;
                a[yy][xx] = 1;
                for(k=1 ; k<=n ; k++)
                    for(l=1 ; l<=m ; l++)
                        if(yy!=k && xx!=l && yy-xx!=k-l && yy+xx!=k+l && a[k][l]==0)
                        {
                            Q.push(k);
                            Q.push(l);
                            path[k][l] = make_pair(yy, xx);
                        }
            }
            if(full())
            {
                print(sy, sx, ey, ex);
                return 0;
            }
        }
}
