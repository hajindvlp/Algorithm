#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, a[101][101];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

void bfs() {
    int i, j, l, d[101][101], acnt = 0;
    int yy, xx, ty, tx;
    queue<pii> Q;

    for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++) d[i][j] = 0;
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(d[i][j] == 0) {
                acnt++;
                Q.push({i, j});
                while(!Q.empty()) {
                    pii t = Q.front();
                    yy = t.first;
                    xx = t.second;
                    Q.pop();
                    for(l=0 ; l<4 ; l++) {
                        ty = yy+dy[l];
                        tx = xx+dx[l];
                        if(ty>0 && ty<=n && tx>0 && tx<=n && d[ty][tx] == 0 && a[yy][xx] == a[ty][tx]) {
                            d[ty][tx] = 1;
                            Q.push({ty, tx});
                        }
                    }
                }
            }
    printf("%d ", acnt);
}

int main() {
    int i, j;
    char s[105];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) {
        scanf("%s", &s[1]);
        for(j=1 ; j<=n ; j++) {
            if(s[j] == 'R') a[i][j] = 0;
            else if(s[j] == 'G') a[i][j] = 1;
            else if(s[j] == 'B') a[i][j] = 2;
        }
    }
    bfs();

    for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++) if(a[i][j] == 1) a[i][j] = 0;
    bfs();
}