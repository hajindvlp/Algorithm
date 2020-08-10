#include <stdio.h>

int p[4][2]; 
double l;

int main() {
  int i, j;
  int mid2, start = 0;

  scanf("%lf", &l);
  for(i=1 ; i<=3 ; i++) scanf("%d %d", &p[i][0], &p[i][1]);

  for(i=1 ; i<=3 ; i++) {
    for(j=1 ; j<=3 ; j++) printf("%d %d\n", p[i][0], p[i][1]);
    if(p[i][0] != p[i][1]) {
      mid2 = p[i][0]+p[i][1];
      printf("%d\n", mid2);
      for(j=i ; j<=3 ; j++) {
        if(p[j][0] <= mid2/2) p[j][0] = mid2 - p[j][0];
        if(p[j][1] <= mid2/2) p[j][1] = mid2 - p[j][1];
      }
      start = mid;
      (l - (double)mid2/2 > 0) ? l = l - (double)mid2/2 : l = l - (double)mid2/2;
    }
  }

  printf("%.1lf", l);
}