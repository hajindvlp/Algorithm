#include <stdio.h>

int main() {
  int n, sum, k;

  scanf("%d", &n);
  for(int i=1 ; i<=1000000 ; i++) {
    sum = i; k = i;
    while(k) sum += k%10, k/=10;
    if(sum == n) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("0\n");
}