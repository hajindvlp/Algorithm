#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;
int n, m, cnt;
int a[1001][1001], visit[1001];

int main() {
  int i, j;
  int xx, yy;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=m ; i++) {
    scanf("%d %d", &xx, &yy);
    a[xx][yy] = a[yy][xx] = 1;
  }

  for(i=1 ; i<=n ; i++) {
    if(!visit[i]) {
      Q.push(i), cnt++;
      while(!Q.empty()) {
        xx = Q.front(), Q.pop();
        for(j=1 ; j<=n ; j++) {
          if(!visit[j] && a[xx][j]) {
            Q.push(j);
            visit[j] = 1;
          }
        }
      }
    }
  }

  printf("%d", cnt);
}