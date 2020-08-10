#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;

queue<pii> Q;
priority_queue<int, vector<int>, greater<int> > ans;
int n, m, k;
int d[101][101];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main() {
    int i, j, l;
    int yy, xx, ty, tx;
    int cnt;
    
    scanf("%d %d %d", &n, &m, &k);
    for(l=1 ; l<=k ; l++) {
        scanf("%d %d %d %d", &yy, &xx, &ty, &tx);
        for(i=xx ; i<tx ; i++) for(j=yy ; j<ty ; j++) d[i][j] = 1;
    }

    for(i=0 ; i<n ; i++) 
        for(j=0 ; j<m ; j++) {
            if(!d[i][j]) {
                cnt = 0;
                Q.push({i, j});
                while(!Q.empty()) {
                    pii t = Q.front();
                    Q.pop();
                    yy = t.first;
                    xx = t.second;
                    cnt++, d[yy][xx] = 1;
                    for(l=0 ; l<4 ; l++) {
                        ty = yy+dy[l];
                        tx = xx+dx[l];
                        if(ty>=0 && ty<n && tx>=0 && tx<m && d[ty][tx] == 0) {
                            d[ty][tx] = 1;
                            Q.push({ty, tx});
                        }
                    }
                }
                ans.push(cnt);
            }
        }

    printf("%d\n", ans.size());
    while(!ans.empty()) printf("%d ", ans.top()), ans.pop();
}