#include <stdio.h>
#include <algorithm>
using namespace std;

int a[101][101], sum[101][101], d[101][101], n;
int asum, asx, asy, aex, aey;

pair<int, pair<int, int> > findmx(int y, int x)
{
    int mx = 0, sx, sy;
    int i, j;
    pair<int, pair<int, int> > tmp;

    for(i=1 ; i<=y ; i++)
        for(j=1 ; j<=x ; j++)
            if(sum[y][x]-sum[i-1][x]-sum[y][j-1]+sum[i-1][j-1]>mx)
            {
                mx = sum[y][x]-sum[i-1][x]-sum[y][j-1]+sum[i-1][j-1];
                sy = i;
                sx = j;
            }
    tmp = make_pair(mx, make_pair(sy, sx));
    return tmp;
}

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]), sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
        {
            pair<int, pair<int, int> > tmp;
            tmp = findmx(i, j);
            if(tmp.first>asum)
            {
                asum = tmp.first;
                asy = tmp.second.first;
                asx = tmp.second.second;
                aey = i;
                aex = j;
            }
        }

    printf("%d\n%d %d %d %d", asum, asx, asy, aex, aey);
    return 0;
}
