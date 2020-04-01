#include <stdio.h>

void pro() {
  int a, b, c, n;
  int s = 0;

  scanf("%d %d %d %d", &a, &b, &c, &n);
  s = a+b+c+n;
  if((float)s/3 == s/3 && a<=s/3 && b<=s/3 && c<=s/3) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

int main() {
  int k;

  scanf("%d", &k);
  while(k--) {
    pro();
  }
}