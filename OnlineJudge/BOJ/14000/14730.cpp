#include <stdio.h>

int main() {
  int n, x, y, sum =0;

  scanf("%d", &n);
  while(n--) scanf("%d %d", &x, &y), sum+=x*y;
  printf("%d", sum);
}