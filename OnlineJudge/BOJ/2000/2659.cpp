#include <stdio.h>

int d[10][10][10][10], cnt;

int main() {
  int i, j, k, l;

  for(i=1 ; i<=9 ; i++)
    for(j=1 ; j<=9 ; j++)
      for(k=1; k<=9 ; k++)
        for(l=1 ; l<=9 ; l++)
          if(!d[i][j][k][l]) d[i][j][k][l] = d[j][k][l][i] = d[k][l][i][j] = d[l][i][j][k] = ++cnt;

  scanf("%d %d %d %d", &i, &j, &k, &l);
  printf("%d", d[i][j][k][l]);
}