#include <stdio.h>

int main() {
  int a, b, c, d;

  scanf("%d %d %d %d", &a, &b, &c, &d);
  c = c+d;
  b = b+c/60;
  a = (a+b/60)%24;
  b %= 60;
  c %= 60;

  printf("%d %d %d", a, b, c);
}