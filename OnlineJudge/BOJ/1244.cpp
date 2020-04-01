#include <stdio.h>

int n, m, a[101];

void boy(int s) {
  int i;

  for(i=s ; i<=n ; i+=s) a[i] = !a[i];
}

void girl(int s) {
  int i;
  
  a[s] ^= 1;
  for(i=1 ; s+i<=n && s-i>=1 ; i++) {
    if(a[s+i] != a[s-i]) break;
    a[s+i] ^= 1, a[s-i] ^= 1;
  }
}

int main() {
  int i;
  int x, y;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for(i=1 ; i<=m ; i++) {
    scanf("%d %d", &x, &y);
    (x == 1) ? boy(y) : girl(y);
  }

  for(i=1 ; i<=n ; i++) {
    printf("%d ", a[i]);
    if(i%20 == 0) printf("\n");
  }
}