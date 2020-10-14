#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 1000000000
using namespace std;

typedef struct {
  int y, x;
  int time;
} Unit;

int n, m, mx = INF;
int ans;
int a[501][501], d[501][501];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
queue<Unit> Q;
Unit y, t;

bool isNight(int time) {
  if((time/m)%2 == 0) return false;
  return true;
}

int main() {
  int i, j;
  int yy, xx, tt, ty, tx;
  bool out;

  cin >> n >> m;
  for(i=1 ; i<=n ; i++) 
    for(j=1 ; j<=n ; j++)
      scanf("%d", &a[i][j]);
  memset(d, INF, sizeof(d[0][0]) * n * n);

  d[1][1] = 0;
  Q.push({1, 1, 0});
  while(!Q.empty()) {
    y = Q.front(), Q.pop();
    yy = y.y;
    xx = y.x;
    tt = y.time;

    if(yy == n && xx == n) {
      if(d[yy][xx] < mx) 
        ans = tt, mx = d[yy][xx];
    } else {
      for(i=0 ; i<4 ; i++) {
        ty = yy+dy[i];
        tx = xx+dx[i];
        if(ty>0 && ty<=n && tx>0 && tx<=n && a[ty][tx]==0 && d[ty][tx]>d[yy][xx]+1) {
          d[ty][tx] = d[yy][xx]+1;
          Q.push({ty, tx, tt+1});
        }
      }
      if(isNight(tt)) {
        for(i=0 ; i<4 ; i++) {
          ty = yy, tx = xx;
          out = false;
          while(1) {
            ty += dy[i], tx += dx[i];
            if(!(ty>0 && ty<=n && tx>0 && tx<=n)) {
              out = true;
              break;
            } if(a[ty][tx] == 0) {
              break;
            }
          }
          if(!out && d[ty][tx] > d[yy][xx]+1) {
            d[ty][tx] = d[yy][xx]+1;
            Q.push({ty, tx, tt+1});
          }
        }
      }
    }    
  }

  for(i=1 ; i<=n ; i++) {
    for(j=1 ; j<=n ; j++) 
      cout << d[i][j] << " ";
    cout << "\n";
  }
  if(ans == 0) printf("-1");
  else {
    cout << ans/m;
    cout << (isNight(ans))? " moon" : " sun";
  }
}