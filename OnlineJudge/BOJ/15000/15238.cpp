#include <stdio.h>

int cnt[201] = {0};
char ans;

int main() {
  int n, i;
  char x;

  scanf("%d ", &n);
  for(i=1 ; i<=n ; i++) {
    scanf("%c", &x);
    cnt[x]++;
    if(cnt[x] > cnt[ans]) ans = x;
  }

  printf("%c %d", ans, cnt[ans]);
}