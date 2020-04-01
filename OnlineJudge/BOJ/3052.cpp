#include <stdio.h>

int check[42];
int cnt;

int main() {
  int i, n;

  for(i=1 ; i<=10 ; i++) {
    scanf("%d", &n);
    if(check[n%42] == 0) cnt++;
    check[n%42] = 1;
  }

  printf("%d", cnt);
}