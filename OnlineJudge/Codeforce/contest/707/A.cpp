#include <stdio.h>

int main() {
  int n, m, i;
  int c = 0;
  char t;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=n*m ; i++) {
    scanf(" %c", &t);
    if(t != 'W' && t != 'B' && t!='G') c = 1;
  }
  if(c) printf("#Color");
  else printf("#Black&White");
}