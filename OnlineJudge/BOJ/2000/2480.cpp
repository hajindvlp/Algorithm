#include <stdio.h>

int main() {
  int a, b, c;
  int ans = 0;

  scanf("%d %d %d", &a, &b, &c);
  if(a == b && b == c) ans = 10000 + a*1000;
  else if(a == b || a == c) ans = 1000 + a * 100;
  else if(a == b || b == c) ans = 1000 + b * 100;
  else if(a == c || c == b) ans = 1000 + c * 100;
  else {
    a = (a>b)?a:b;
    a = (a>c)?a:c;
    ans = a*100;
  }

  printf("%d", ans);
}