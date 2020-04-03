#include <stdio.h>

int main() {
  int a, b, c, d, e;
  int t1, t2;

  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  t1 = b/d;
  if(b%d) t1++;
  t2 = c/e;
  if(c%e) t2++;
  t1 = (t1>t2)?t1:t2;
  printf("%d", a-t1);  
}