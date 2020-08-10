// 룹 내 bfs

#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;
int n;
int a[101][101], visit[101][101];
int cnt, ans, maxH;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main() {
  int i, j, k, l;
  int yy, xx, ty, tx;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) 
    for(j=1 ; j<=n ; j++) {
      scanf("%d", &a[i][j]);
      maxH = (maxH > a[i][j]) ? maxH : a[i][j];
    }

  for(k=1 ; k<=maxH ; k++) {
    for(i=1 ; i<=n ; i++)
      for(j=1 ; j<=n ; j++)
        visit[i][j] = 0;
    cnt = 0;
    for(i=1 ; i<=n ; i++)
      for(j=1 ; j<=n ; j++) {
        if(visit[i][j] == 0 && a[i][j] >= k) {
          cnt++;
          Q.push(i), Q.push(j);
          while(!Q.empty()) {
            yy = Q.front(), Q.pop();
            xx = Q.front(), Q.pop();
            for(l=0 ; l<4 ; l++) {
              ty = yy+dy[l];
              tx = xx+dx[l];
              if(ty>0 && ty<=n && tx>0 && tx<=n && a[ty][tx]>=k && visit[ty][tx]==0) {
                Q.push(ty);
                Q.push(tx);
                visit[ty][tx] = 1;
              }
            }
          }
        }
      }

    // printf("%d ", cnt);
    ans = (ans < cnt) ? cnt : ans;
  }

  printf("%d", ans);  
}