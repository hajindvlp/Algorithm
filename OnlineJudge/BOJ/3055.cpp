#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;

int n, m;
int sx, sy, ex, ey;
int d[51][51];
int a[51][51], w[2501][2], wn;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int ans;

queue<int> Q;

int abs(int x) {
  if(x<0) return -x;
  return x;
}

int main() {
  int i, j, flag;
  char t[55];

  int yy, xx, ty, tx;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=n ; i++) {
    scanf("%s", &t[1]);
    for(j=1 ; j<=m ; j++) {
      if(t[j] == 'D') sy = i, sx = j;
      else if(t[j] == 'S') ey = i, ex = j;
      else if(t[j] == 'X') a[i][j] = -1;
      else if(t[j] == '*') ++wn, w[wn][0] = i, w[wn][1] = j;
      d[i][j] = INF;
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
      if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx] != -1 && d[ty][tx] > d[yy][xx]+1) {
        for(j=1 ; j<=wn ; j++)
          if(abs(ty-w[j][0]) + abs(tx-w[j][1]) <= d[yy][xx]+1) flag = 1;
        if(flag == 0) {
          d[ty][tx] = d[yy][xx]+1;
          Q.push(ty);
          Q.push(tx);
        } 
      }
    }
  }

  for(i=1 ; i<=n ; i++) {
    for(j=1 ; j<=m ; j++) printf("%d ", d[i][j]);
    printf("\n");
  }

  if(d[ey][ex] >= INF) printf("KAKTUS");
  else printf("%d", ans);
  return 0;
}