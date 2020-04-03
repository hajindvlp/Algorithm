#include <stdio.h>

int a[21], n, m, acnt;

void rec(int lev, int sum, int cnt) {
  if(lev>n) {
    if(sum == m && cnt>=1) acnt++;
  } else {
    rec(lev+1, sum+a[lev], cnt+1);
    rec(lev+1, sum, cnt);
  }
}

int main() {
  int i;

  scanf("%d %d", &n, &m);
  for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);
  rec(1, 0, 0);

  printf("%d", acnt);
}