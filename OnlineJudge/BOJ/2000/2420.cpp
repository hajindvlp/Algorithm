#include <stdio.h>

int main() {
  long long int a, b;
  long long int c;

  scanf("%lld %lld", &a, &b);
  c = a-b;
  if(c < 0) c = -c;
  printf("%lld", c);
}