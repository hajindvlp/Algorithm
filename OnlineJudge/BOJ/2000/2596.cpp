#include <stdio.h>
#define INF 100000000

int n, a[7];
int dict[9][7] = {
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 1},
  {0, 0, 1, 1, 1, 0, 0},
  {0, 1, 0, 0, 1, 1, 0},
  {0, 1, 0, 1, 0, 0, 1},
  {0, 1, 1, 0, 1, 0, 1},
  {0, 1, 1, 1, 0, 1, 0}
};
char ans[10];

int getDist(int idx) {
  int i, j, cnt=0, mn = INF, l, tcnt = 0;

  for(i=1 ; i<=8 ; i++) {
    cnt = 0;

    for(j=1 ; j<=6 ; j++) 
      if(a[j] != dict[i][j])
        cnt++;
    
    if(cnt < mn) mn = cnt, l = i;
  }

  for(i=1 ; i<=8 ; i++) {
    cnt = 0;

    for(j=1 ; j<=6 ; j++) 
      if(a[j] != dict[i][j])
        cnt++;
    
    if(cnt == mn) tcnt++;
  }
  if(tcnt >= 2) return 1;

  ans[idx] = 'A' + l - 1;
  
  return 0;
}

int main() {
  int i, j;
  char tmp[55];

  scanf("%d %s", &n, &tmp[1]);
  for(i=1 ; i<=n ; i++) {
    for(j=1 ; j<=6 ; j++)
      a[j] = tmp[(i-1)*6+j] - '0';
    if(getDist(i)) {
      printf("%d", i);
      return 0;
    }
  }
  printf("%s", &ans[1]);
  return 0;
}