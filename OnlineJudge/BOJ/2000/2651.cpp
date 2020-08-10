#include <stdio.h>
#define INF 100000000

int n, m;
int a[102], f[102];
int ds[102], d[102], path[102];
int ans[102], acnt;

int main() {
  int i, j, x;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=m+1 ; i++) {
    scanf("%d", &a[i]);
    ds[i] = a[i] + ds[i-1];
    d[i] = INF;
  }

  for(i=1 ; i<=m ; i++) scanf("%d", &f[i]);

  for(i=1 ; i<=m+1 ; i++) 
    for(j=0 ; j<i ; j++) 
      if(ds[i] - ds[j] <= n && d[i] > d[j] + f[i]) {
        d[i] = d[j] + f[i];
        path[i] = j;
      }

  printf("%d\n", d[m+1]);
  x = path[m+1];
  while(x != 0) {
    ans[++acnt] = x;
    x = path[x];
  }

  printf("%d\n", acnt);
  for(i=acnt ; i>=1 ; i--) printf("%d ", ans[i]);
}