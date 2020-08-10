#include <stdio.h>

int n, m;
int a[101][2], d[10001][2], t[10001], visit[10001][2];

int main() {
  int i, j;
  int x, y;

  scanf("%d %d", &n, &m);
  d[0][1] = d[0][0] = 1;
  for(i=1 ; i<=m ; i++) {
    scanf("%d %d", &x, &y);
    for(j=x ; j<=n ; j++) {
    }

    for(j=0 ; j<=n ; j++) visit[j] = 0, d[j] = t[j];
  }

  printf("%d", d[n]);
}