#include <stdio.h>
#include <string.h>

int main() {
  char s[20];
  int n, i, j;

  scanf("%s", &s[1]);
  n = strlen(&s[1]);

  printf(".");
  for(i=1 ; i<=n ; i++) {
    if(i%3) printf(".#..");
    else printf(".*..");
  }
  printf("\n");

  printf(".");
  for(i=1 ; i<=n ; i++) {
    if(i%3) printf("#.#.");
    else printf("*.*.");
  }
  printf("\n");

  for(i=1 ; i<=n ; i++) {
    if(i%3 == 1 && i!=1) printf(".%c.", s[i]);
    else if(i%3) printf("#.%c.", s[i]);
    else printf("*.%c.*", s[i]);
  }
  if(n%3) printf("#");
  printf("\n"); 

  printf(".");
  for(i=1 ; i<=n ; i++) {
    if(i%3) printf("#.#.");
    else printf("*.*.");
  }
  printf("\n");

  printf(".");
  for(i=1 ; i<=n ; i++) {
    if(i%3 != 0) printf(".#..");
    else printf(".*..");
  }
  printf("\n");
}