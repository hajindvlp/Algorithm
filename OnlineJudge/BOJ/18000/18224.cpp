#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;

struct Unit {
  int y, x;
  int time;
};

int n, m, mx = INF;
int ans;
int a[501][501], d[501][501];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
queue<struct Unit> Q;
struct Unit y, t;

bool day(int time) {
  if((time/m)%2 == 0) return true;
  return false;
}

int main() {
  int i, j;
  int yy, xx, ty, tx;
  bool out;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++)
    scanf("%d", &a[i][j]), d[i][j] = INF;

  d[1][1] = 0;
  Q.push({1, 1, 0});
  while(!Q.empty()) {
    y = Q.front(), Q.pop();
    yy = y.y;
    xx = y.x;

    if(yy == n && xx == n && d[yy][xx] < mx) ans = y.time, mx = d[yy][xx];

    for(i=0 ; i<4 ; i++) {
      ty = yy+dy[i];
      tx = xx+dx[i];
      if(ty>0 && ty<=n && tx>0 && tx<=n && a[ty][tx]==0 &&d[ty][tx]>d[yy][xx]+1) {
        d[ty][tx] = d[yy][xx]+1;
        Q.push({ty, tx, y.time+1});
      }
    }
    if(!day(y.time)) {
      for(i=0 ; i<4 ; i++) {
        ty = yy, tx = xx;
        out = false;
        while(1) {
          ty += dy[i], tx += dx[i];
          if(!(ty>0 && ty<=n && tx>0 && tx<=n)) {
            out = true;
            break;
          } if(a[ty][tx] != 1) {
            break;
          }
        }
        if(!out && d[ty][tx] > d[yy][xx]+1) {
          d[ty][tx] = d[yy][xx]+1;
          Q.push({ty, tx, y.time+1});
        }
      }
    }
  }
  if(ans == 0) printf("-1");
  else {
    printf("%d", ans/m);
    (day(ans))?printf(" sun"):printf(" moon");
  }
}