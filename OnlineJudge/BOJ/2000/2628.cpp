#include <stdio.h>
#include <algorithm>
using namespace std;

int w, h, n;
int r[101], c[101];
int rcnt, ccnt;
int rmx, cmx;

int main() {
  int i, x, y;

  scanf("%d %d %d", &w, &h, &n);

  for(i=1 ; i<=n ; i++) {
    scanf("%d %d", &x, &y);
    (x) ? r[++rcnt] = y : c[++ccnt] = y;
  }
  r[++rcnt] = w, c[++ccnt] = h;
  sort(r+1, r+rcnt+1);
  sort(c+1, c+ccnt+1);

  for(i=1 ; i<=rcnt ; i++) if(r[i] - r[i-1] > rmx) rmx = r[i] - r[i-1];
  for(i=1 ; i<=ccnt ; i++) if(c[i] - c[i-1] > cmx) cmx = c[i] - c[i-1];

  printf("%d", rmx * cmx);
}