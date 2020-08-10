#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

typedef pair<int, pair<int, int> > piii;

queue<piii> Q;
int n, m, a[1001][1001], d[2][1001][1001];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

int main() {
    int i, j, k;
    int ff, yy, xx, ty, tx;
    char s[1003];

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++) {
        scanf("%s", &s[1]);
        for(j=1 ; j<=m ; j++) {
            if(s[j] == '1') a[i][j] = 1;
            d[0][i][j] = d[1][i][j] = INF;
        }
    }

    d[0][1][1] = 1;
    Q.push({0, {1, 1}});
    while(!Q.empty()) {
        piii t = Q.front();
        Q.pop();
        ff = t.first;
        yy = t.second.first;
        xx = t.second.second;
        for(i=0 ; i<4 ; i++) {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m) {
                if(a[ty][tx] == 0 && d[ff][ty][tx] > d[ff][yy][xx]+1) {
                    d[ff][ty][tx] = d[ff][yy][xx] +1;
                    Q.push({ff, {ty, tx}});
                } else if(a[ty][tx] == 1 && ff == 0 && d[ff+1][ty][tx] > d[ff][yy][xx]+1) {
                    d[ff+1][ty][tx] = d[ff][yy][xx]+1;
                    Q.push({ff+1, {ty, tx}});
                }
            }
        }
    }

    if(d[0][n][m] == INF && d[1][n][m] == INF) printf("-1");
    else printf("%d", (d[0][n][m]<d[1][n][m])?d[0][n][m]:d[1][n][m]);
}