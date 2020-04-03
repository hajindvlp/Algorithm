#include <stdio.h>

int main() {
  int a, b, c, ans;

  scanf("%d %d %d", &a, &b, &c);
  if(b == c) {
    printf("-1");
    return 0;
  }
  ans = a/(c-b)+1;
  if(ans <= 0) printf("-1");
  else printf("%d", ans);
}