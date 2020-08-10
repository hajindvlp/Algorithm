#include <stdio.h>

int n, m;
int a[51], c[101][51];
int acnt, ans[101][51];

int cmp(int r, int start) {
  int i;
  int flag1 = 1, flag2 = 1;

  for(i=1 ; i<=n ; i++) 
    if(c[r][(i+start-1) % n + 1] != a[i]) 
      flag1 = 0;
  for(i=1 ; i<=n ; i++) 
    if((c[r][(i+start-1) % n + 1] + 2) % 4 != a[n-i+1] % 4) 
      flag2 = 0;
  return flag1 || flag2;
}

int main() {
  int i, j, k;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for(i=1 ; i<=m ; i++) {
    for(j=1 ; j<=n ; j++) scanf("%d", &c[i][j]);
    for(j=1 ; j<=n ; j++) {
      if(cmp(i, j)) {
        acnt++;
        for(k=1 ; k<=n ; k++)
          ans[acnt][k] = c[i][k];
      }
    }
  }

  printf("%d\n", acnt);
  for(i=1 ; i<=acnt ; i++) {
    for(j=1 ; j<=n ; j++) printf("%d ", ans[i][j]);
    printf("\n");
  }
  return 0;
}