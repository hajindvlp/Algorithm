#include <stdio.h>

bool isI(int x, int y) {
  return (x == (x/y) * y);
}

int main() {
  int i;
  int n;
  bool yep = true;

  scanf("%d", &n);
  n*=n;
  for(i=1 ; i*i<n ; i++) {
    if(n%i == 0 && (n/i+i)/2 > 0 && (n/i-i)/2 > 0 && isI(n, i)) {
      printf("%d %d", (n/i+i)/2, (n/i-i)/2);
      yep = false;
      break;
    }
  }
  if(yep) printf("-1");
}