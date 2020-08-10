#include <stdio.h>

int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  b += c;
  if(b/60) {
    a = (a+b/60)%24;
    b = (b+60)%60;
  }
  printf("%d %d\n", a, b);
}