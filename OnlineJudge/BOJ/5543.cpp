#include <stdio.h>

int main() {
  int a, b, x;

  scanf("%d", &a);
  scanf("%d", &x);
  a = (x<a)?x:a;
  scanf("%d", &x);
  a = (x<a)?x:a;

  scanf("%d", &b);
  scanf("%d", &x);
  b = (x<b)?x:b;

  printf("%d", a+b-50);
}