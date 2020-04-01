#include <stdio.h>
#include <math.h>

int main() {
  int n;

  scanf("%d", &n);
  printf("%lf\n%lf", (double)n*n*M_PI, (double)2*n*n);
}