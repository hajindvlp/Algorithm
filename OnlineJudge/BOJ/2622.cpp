#include <stdio.h>

int n, cnt;

int main() {
  int i, j, k;

  scanf("%d", &n);
  for(i=1 ; i<=n/3 ; i++) {
    for(j=n/2-i ; j<=n ; j++) {
      k = n-(i+j);
      if(i <= j && j <= k && k < i + j) {
        // printf("%d %d %d\n", i, j, k);
        cnt++;
      }
      else if(j>k) break;
      // else break;
    }
  }
  printf("%d", cnt);
}