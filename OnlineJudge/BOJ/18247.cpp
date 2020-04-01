#include <stdio.h>

int main() {
  int t, m, n;

  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    if(n < 12 || m < 4) {
      printf("-1\n");
    } else {
    printf("%d\n", 11 * m + 4); 
    } 
  }
}