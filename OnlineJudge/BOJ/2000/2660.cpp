#include <stdio.h>
#define INF 100000000

int a[51][51], d[51], n, mx = INF;
int ans[51], acnt;

int main() {
  int i, j, k;
  int x, y;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++)
  for(j=1 ; j<=n ; j++)
    a[i][j] = INF;

  while(1) {
    scanf("%d %d", &x, &y);
    if(x == -1 && y == -1) break;

    a[x][y] = a[y][x] = 1;
  }

  for(k=1 ; k<=n ; k++)
  for(i=1 ; i<=n ; i++) 
  for(j=1 ; j<=n ; j++) 
    if(a[i][k] + a[k][j] < a[i][j]) 
      a[i][j] = a[i][k]+a[k][j];

  for(i=1 ; i<=n ; i++) {
    for(j=1 ; j<=n ; j++) 
      if(i!=j && a[i][j] > d[i]) 
        d[i] = a[i][j];
    if(d[i] < mx) mx = d[i];
  } 
  
  for(i=1 ; i<=n ; i++)
    if(d[i] == mx)
      ans[++acnt] = i;

    printf("%d %d\n", mx, acnt);
    for(i=1 ; i<=acnt ; i++) 
      printf("%d ", ans[i]);
}