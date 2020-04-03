#include <stdio.h>
#include <math.h>

int main() {
  int a, b, c;
  
  scanf("%d %d %d", &a, &b, &c);
  printf("%d %d", (int)(a/sqrt(b*b + c*c)*b), (int)(a/sqrt(b*b + c*c)*c));
}