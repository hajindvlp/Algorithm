#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

void pro() {
  int n, i, j;
  int a[10] = {1, -1, -1, -1};

  scanf("%d", &n);
  for(j=1 ; j<=2 ; j++) {
    a[j] = -1;
    for(i=a[j-1]+1 ; i*i<=n ; i++) 
      if(n%i == 0) {
        a[j] = i;
        n/=i;
        break;
      }

    if(a[j] == -1) {
      printf("NO\n");
      return;
    }
  }
  a[j] = n;
  if(a[j-1] != a[j]) {
    printf("YES\n");
    for(j=1 ; j<=3 ; j++) printf("%d ", a[j]);
  }
  else printf("NO");
  printf("\n");
}

int main() {
  int k;

  scanf("%d", &k);
  while(k--) pro();
}