#include <stdio.h>

int n, a[101], check[101];
int visit[101], ans[101], acnt;

int main() {
  int i, j, x;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);

  for(i=1 ; i<=n ; i++) 
    if(!visit[i]) {
      for(j=1 ; j<=n ; j++) check[j] = 0;
      
      x = i;
      while(1) {
        check[x] = 1;
        x = a[x];
        if(x == i) {
          check[x] = 1;
          for(j=1 ; j<=n ; j++) 
            if(check[j] && !visit[j])
              ans[++acnt] = j, visit[j] = 1;
          break;
        } else if(check[x] == 1) break;
      }
    }

  printf("%d\n", acnt);
  for(i=1 ; i<=n ; i++) if(visit[i] == 1) printf("%d\n", i);

  return 0;
} 