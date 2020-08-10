#include <stdio.h>

int a[101][101], sum;

int main() {
  int p, q, r, s;

  for(int i=1 ; i<=4 ; i++) {
    scanf("%d %d %d %d", &p, &q, &r, &s);
    for(int j=q ; j<=s-1 ; j++) for(int k=p ; k<=r-1 ; k++) a[j][k] = 1;
  }

  for(int i=1 ; i<=10 ; i++) {
    for(int j=1 ; j<=10 ; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }

  for(int i=1 ; i<=100 ; i++) for(int j=1 ; j<=100 ; j++) sum+=a[i][j];
  printf("%d", sum);
}