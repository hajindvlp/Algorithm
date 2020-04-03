#include <stdio.h>

int pro() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  if(a == b && b == c && c == 0) return 0;

  if((c-a)%b!=0 || (c-a)/b < 0) printf("X\n");
  else printf("%d\n", (c-a)/b+1);
  return 1;
}


int main() {
  while(pro());  
}