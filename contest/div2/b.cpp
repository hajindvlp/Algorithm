#include <stdio.h>

unsigned long long nc2(int n) {
  return (unsigned long long) n * (n-1) /2;
} 

void pro() {
  int i, n, x, cnt, count[50];
  unsigned long long ans = 0;

  for(i=0 ; i<50 ; i++) count[i] = 0;

  scanf("%d",&n);
  for(i=1 ; i<=n ; i++) {
    scanf("%d",&x);
    cnt = 0;
    while(x/=2) cnt++;
    count[cnt]++;
  }

  for(i=0 ; i<50 ; i++) ans += (count[i]>0) ? nc2(count[i]) : 0;
  printf("%llu\n", ans);
}

int main() {
  int t;

  scanf("%d",&t);
  while(t--) pro();
}