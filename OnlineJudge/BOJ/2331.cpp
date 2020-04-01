// 간단한 simulation
#include <stdio.h>
using namespace std;
 
int n, p, visit[236120];

int pow(int x, int p) {
  int i, ret = 1;

  for(i=1 ; i<=p ; i++) ret *= x;
  return ret;
}

int main() {
  int i, j, x, nx, cnt = 0, ans;

  scanf("%d %d", &n, &p);

  nx = n;
  while(1) {
    cnt++;
    x = nx;
    if(visit[x]) {
      printf("%d", visit[x]-1);
      return 0;
    } else {
      visit[x] = cnt;
      nx = 0;
      while(x) {
        nx += pow(x%10, p);
        x/=10;
      } 
    }
  }
}