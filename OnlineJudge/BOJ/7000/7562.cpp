#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void pro() {
  queue<pii> Q;
  int n, d[301][301];
  int sy, sx, ey, ex, yy, xx, ty, tx;
  int i, j;

  scanf("%d", &n);
  scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
  for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++) d[i][j] = INF;
  sy++, sx++, ey++, ex++;
  Q.push({sy, sx});
  d[sy][sx] = 0;
  while(!Q.empty()) {
    pii t = Q.front();
    yy = t.first;
    xx = t.second;
    Q.pop();
    for(i=0 ; i<8 ; i++) {
      ty = yy+dy[i];
      tx = xx+dx[i];
      if(ty>0 && ty<=n && tx>0 && tx<=n && d[ty][tx] > d[yy][xx]+1) {
        d[ty][tx] = d[yy][xx]+1;
        Q.push({ty, tx});
      }
    }
  }

  printf("%d\n", d[ey][ex]);
}

int main() {
  int T;

  scanf("%d", &T);
  while(T--) pro();
}