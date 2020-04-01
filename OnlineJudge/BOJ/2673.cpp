#include <stdio.h>
using namespace std;

int n;
int a[101][101], dp[101][101];

int main() {
  int x, y, i, j;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) {
    scanf("%d %d", &x, &y);
    a[x][y] = a[y][x] = 1;
  }

  for(i=1 ; i<=100 ; i++) {
    for(j=1 ; j<=100 ; j++) {

    }
  }
}