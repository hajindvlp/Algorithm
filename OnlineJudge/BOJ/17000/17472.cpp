#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF 1000000000
using namespace std;

queue<int> Q;
int n, m;
int a[11][11], d[101][101], color[11][11];
int tc;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int dist[105], visit[105], v, mn, sum;

int main() {
  int i, j, k;
  int yy, xx, ty, tx, sx, sy, sc;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++) scanf("%d", &a[i][j]);

  for(i=1 ; i<=n ; i++) 
    for(j=1 ; j<=m ; j++) 
      if(a[i][j] && !color[i][j]) {
        Q.push(i);
        Q.push(j);
        tc++;
        color[i][j] = tc;
        while(!Q.empty()) {
          yy = Q.front(), Q.pop();
          xx = Q.front(), Q.pop();
          for(k=0 ; k<4 ; k++) {
            ty = yy + dy[k];
            tx = xx + dx[k];
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx] && !color[ty][tx]) {
              Q.push(ty);
              Q.push(tx);
              color[ty][tx] = tc;
            }
          }
        }
      }

  for(i=1 ; i<=n ; i++) {
    for(j=1 ; j<=m ; j++) printf("%d ", color[i][j]);
    printf("\n");
  }
  printf("\n");

  for(i=1 ; i<=n ; i++) {
    sc = 0;
    for(j=1 ; j<=m ; j++) {
      if(color[i][j] != sc && color[i][j] != 0) {
        if(sc == 0) {
          sy = i, sx = j;
          sc = color[i][j];
        } else if(j-sx-1 >= 2) {
          if(d[sc][color[i][j]] > j-sx-1 || d[sc][color[i][j]] == 0)
            d[sc][color[i][j]] = d[color[i][j]][sc] = j-sx-1;
          sc = color[i][j];
        } else {
          sc = color[i][j];
          sy = i, sx = j;
        }
      } else if(color[i][j] == sc && sc !=0 ) {
        sy = i, sx = j;
      }
    }
  }

  for(j=1 ; j<=m ; j++) {
    sc = 0;
    for(i=1 ; i<=n ; i++) {
      if(color[i][j] != sc && color[i][j] != 0) {
        if(sc == 0) {
          sy = i, sx = j;
          sc = color[i][j];
        } else if(i-sy-1 >= 2) {
          if(d[sc][color[i][j]] > i-sy-1 || d[sc][color[i][j]] == 0)
            d[sc][color[i][j]] = d[color[i][j]][sc] = i-sy-1;
          sc = color[i][j];
        } else {
          sc = color[i][j];
          sy = i, sx = j;
        }
      } else if(color[i][j] == sc && sc !=0 ) {
        sy = i, sx = j;
      }
    }
  }

  for(i=1 ; i<=tc ; i++) {
    for(j=1 ; j<=tc ; j++) printf("%d ", d[i][j]);
    printf("\n");
  }

  for(i=1 ; i<=tc ; i++) dist[i] = INF;
  dist[1] = 0;

  for(i=1 ; i<=tc ; i++) {
    mn = INF;
    for(j=1 ; j<=tc ; j++) 
      if(!visit[j] && mn > dist[j]) {
        v = j;
        mn = dist[j];
      }
    visit[v] = 1;
    sum+=dist[v];
    for(j=1 ; j<=tc ; j++) 
      if(d[v][j] != 0 && dist[j] > d[v][j])
        dist[j] = d[v][j];
  }

  printf("%d", sum);
}