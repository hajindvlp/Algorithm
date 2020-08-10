#include <stdio.h>

int n, a[129][129];
int wcnt, bcnt;

void rec(int sy, int sx, int w) {
  int i, j, c;
 
  c = a[sy][sx];
  for(i=sy ; i<sy+w ; i++)
    for(j=sx ; j<sx+w ; j++) 
      if(a[i][j] != c) {
        rec(sy, sx, w/2);
        rec(sy+w/2, sx, w/2);
        rec(sy, sx+w/2, w/2);
        rec(sy+w/2, sx+w/2, w/2);
        return;
      }
  (c) ? bcnt++ : wcnt++;
  return;
}

int main() {
  int i, j;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++)
    for(j=1 ; j<=n ; j++)
      scanf("%d", &a[i][j]);

  rec(1, 1, n);

  printf("%d\n%d", wcnt, bcnt);
}