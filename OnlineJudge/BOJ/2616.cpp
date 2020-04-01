#include <stdio.h>

int n, m, a[50001], s[50001], mx[50001][3];
int ans;

int max(int x, int y) {
  if(x > y) return x;
  return y;
}

int main() {
  int i, j;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i-1] + a[i];
  }
  scanf("%d", &m);

  for(i=m ; i<=n ; i++) {
    mx[i][0] = max(s[i] - s[i-m], mx[i-1][0]);
    mx[i][1] = max(mx[i-m][0] + s[i] - s[i-m], mx[i-1][1]);
    mx[i][2] = max(mx[i-m][1] + s[i] - s[i-m], mx[i-1][2]);
  }

  for(i=1 ; i<=n ; i++) ans = max(max(ans, mx[i][0]), max(mx[i][1], mx[i][2]));
  printf("%d", ans);
}