#include <stdio.h>

char s[20] = "+_)(*&^%$#@!./,;{}";

int check() {
  int n, i, j;
  char p;

  int isL, isU, isD, isS;
  isL = isU = isD = isS = 0;

  scanf("%d ", &n);
  for(i=1 ; i<=n ; i++) {
    scanf("%c", &p);
    if(p >= 'a' && p <= 'z') isL = 1;
    else if(p >= 'A' && p <= 'Z') isU = 1;
    else if(p >= '0' && p <= '9') isD = 1;
    for(j=0 ; j<18 ; j++) if(p == s[j]) isS = 1;
  }

  if(n >= 12 && isL && isU && isD && isS) printf("valid\n");
  else printf("invalid\n");
}

int main() {
  int T;

  scanf("%d", &T);
  for(int i=1 ; i<=T ; i++) check();
}