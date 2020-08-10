#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

typedef pair<int, pair<int, int> > pp;
queue<pp> Q;

int n, scnt, ecnt;
int a[51][51], d[3][51][51];
int sx, sy, sr, ex, ey, er;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int canR(int r, int y, int x) {
    int i, j;

    if(x>1 && x<n && y>1 && y<n) {
        for(i=y-1 ; i<=y+1 ; i++) 
            for(j=x-1 ; j<=x+1 ; j++) 
                if(a[i][j]) {
                    return 0;
                }
        return 1;
    } else return 0;
}

int canGo(int r, int y, int x) {
    int i;
    if(r == 0) {
        if(x>1 && x<n) {
            if(a[y][x-1] || a[y][x] || a[y][x+1]) return 0;
            else return 1;
        }
    } else {
        if(y>1 && y<n) {
            if(a[y-1][x] || a[y][x] || a[y+1][x]) return 0;
            else return 1;
        }
    }
    return 0;
}

int main()
{
    int i, j, k;
    char tmp[53];
    int rr, yy, xx, tr, ty, tx;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=n ; j++)
        {
            if(tmp[j] == '1') a[i][j] = 1;
            else if(tmp[j] == 'B') {
                scnt++;
                if(scnt == 2) sy = i, sx = j;
                if(scnt == 3) {
                    if(j>1 && tmp[j-1] == 'B') sr = 0;
                    else sr = 1;
                }
            }
            else if(tmp[j] == 'E') {
                ecnt++;
                if(ecnt == 2) ey = i, ex = j;
                if(ecnt == 3) {
                    if(j>1 && tmp[j-1] == 'E') er = 0;
                    else er = 1;
                }
            }

            d[1][i][j] = d[0][i][j] = INF;
        }
    }

    Q.push({sr, {sy, sx}});
    d[sr][sy][sx] = 0;
    while(!Q.empty())
    {
        pp tt = Q.front();
        rr = tt.first;
        yy = tt.second.first;
        xx = tt.second.second;
        Q.pop();

        if(canR(rr, yy, xx) && d[(rr+1)%2][yy][xx] > d[rr][yy][xx]+1) {
            d[(rr+1)%2][yy][xx] = d[rr][yy][xx]+1;
            Q.push({(rr+1)%2, {yy, xx}});
        }
        for(i=0 ; i<4 ; i++) {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(canGo(rr, ty, tx) && d[rr][ty][tx] > d[rr][yy][xx]+1) {
                d[rr][ty][tx] = d[rr][yy][xx]+1;
                Q.push({rr, {ty, tx}});
            }
        }
    }

    if(d[er][ey][ex] >= INF) printf("0");
    else printf("%d", d[er][ey][ex]);
    return 0;
}
