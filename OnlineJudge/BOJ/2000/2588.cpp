#include <stdio.h>

int main() {
  char b[5];
  int a, t, bN=0, i;

  scanf("%d %s", &a, &b[1]);
  for(i=3 ; i>=1 ; i--) {
    printf("%d\n", a*(b[i]-'0'));
    bN = bN*10 + (b[3-i+1]-'0');
  } 

  printf("%d", a*bN);
}