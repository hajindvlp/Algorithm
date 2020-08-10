#include <stdio.h>
#include <queue>
#include <algorithm>
#define abs(x) ((x)<0)?-(x):x
#define INF 1000000000

using namespace std;

int n, m;
int sx, sy, ex, ey;
int a[51][51], d[51][51];
int wd[51][51], w[2501][2], wn;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int ans;

queue<int> Q;

int main() {
    int i, j, flag;
    char t[55];

    int yy, xx, ty, tx;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++) {
        scanf("%s", &t[1]);
        for(j=1 ; j<=m ; j++) {
            if(t[j] == 'S') sy = i, sx = j;
            else if(t[j] == 'D') ey = i, ex = j, a[i][j] = 2;
            else if(t[j] == 'X') a[i][j] = -1;
            else if(t[j] == '*') ++wn, w[wn][0] = i, w[wn][1] = j;
            d[i][j] = wd[i][j] = INF;
        }
    }

    for (i = 1; i <= wn; i++) {
        Q.push(w[i][0]);
        Q.push(w[i][1]);
        wd[w[i][0]][w[i][1]] = 0;
        while (!Q.empty()) {
            yy = Q.front(), Q.pop();
            xx = Q.front(), Q.pop();

            for (j = 0; j < 4; j++) {
                ty = yy + dy[j];
                tx = xx + dx[j];
                if (ty > 0 && ty <= n && tx > 0 && tx <= m && a[ty][tx] != -1 && a[ty][tx]!=2 && wd[ty][tx] > wd[yy][xx] + 1) {
                    wd[ty][tx] = wd[yy][xx] + 1;
                    Q.push(ty);
                    Q.push(tx);
                }
            }
        }
    }

    Q.push(sy);
    Q.push(sx);
    d[sy][sx] = 0;
    while(!Q.empty()) {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();

        for(i=0 ; i<4 ; i++) {
            ty = yy+dy[i];
            tx = xx+dx[i];
            flag = 0;
            if (ty > 0 && ty <= n && tx > 0 && tx <= m && a[ty][tx] != -1 && d[ty][tx] > d[yy][xx] + 1 && wd[ty][tx] > d[yy][xx] + 1) {
                d[ty][tx] = d[yy][xx]+1;
                Q.push(ty);
                Q.push(tx);
            }
        }
    }

    if(d[ey][ex] >= INF) printf("KAKTUS");
    else printf("%d", d[ey][ex]);
    return 0;
}