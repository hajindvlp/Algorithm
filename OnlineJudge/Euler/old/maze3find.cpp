#include <stdio.h>
#include <deque>
#define INF 1000000000;
using namespace std;

int n;
int a[51][51][51], d[51][51][51];
int dz[6] = {1, 0, 0, -1, 0, 0}, dy[6] = {0, 1, 0, 0, -1, 0}, dx[6] = {0, 0, 1, 0, 0, -1};
deque<int> Q;

int main()
{
    int i, j, k;
    int zz, yy, xx, tz, ty, tx;
    char tmp[52];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
        {
            scanf("%s", &tmp[1]);
            for(k=1 ; k<=n ; k++)
                a[i][j][k] = '1'-tmp[k];
        }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            for(k=1 ; k<=n ; k++)
                d[i][j][k] = INF;

    Q.push_front(1);
    Q.push_front(1);
    Q.push_front(1);
    d[1][1][1] = 0;
    while(!Q.empty())
    {
        zz = Q.front(), Q.pop_front();
        yy = Q.front(), Q.pop_front();
        xx = Q.front(), Q.pop_front();
        for(i=0 ; i<=5 ; i++)
        {
            tz = zz+dz[i];
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(tz>0 && tz<=n && ty>0 && ty<=n && tx>0 && tx<=n && d[tz][ty][tx]>d[zz][yy][xx]+a[zz][yy][xx])
            {
                d[tz][ty][tx] = d[zz][yy][xx]+a[zz][yy][xx];
                if(a[tz][ty][tx] == 0)
                    Q.push_front(tx), Q.push_front(ty), Q.push_front(tz);
                else
                    Q.push_back(tz), Q.push_back(ty), Q.push_back(tx);
            }
        }
    }

    printf("%d", d[n][n][n]);
    return 0;
}
