#include <stdio.h>

void pro() {
  int n, m, a[101][101] = {0};
  int ans = 0, cnt;
  int i, j, k;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++) a[i][j] = 0, scanf("%d", &a[i][j]);
  for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++)
    if(a[i][j] == 1) {
      cnt = 0;
      for(k=i ; k<=n ; k++) if(a[k][j] == 0) cnt++;
      ans += cnt;
    }
  printf("%d\n", ans);
}

int main() {
  int t;

  scanf("%d", &t);
  while(t--) pro();
}