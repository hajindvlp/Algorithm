#include <stdio.h>
#include <algorithm>
using namespace std;

long long int a, d[300005][2][2], mx;

void pro() {
  int n, q, i;

  for(i=0 ; i<= 300000 ; i++) d[i][0][0] = d[i][0][1] = d[i][1][0] = d[i][1][1] = 0;
  mx = 0;

  scanf("%d %d", &n, &q);
  for(i=1 ; i<=n ; i++) {
    scanf("%lld", &a);

    d[i][0][0] = max(d[i-1][1][0], d[i-1][0][0]);
    d[i][0][1] = max(d[i-1][1][1], d[i-1][0][1]);

    d[i][1][0] = max(d[i-1][1][1] - a, d[i-1][0][1] - a);
    d[i][1][1] = max(a, max(a + d[i-1][0][0], a + d[i-1][1][0]));

    mx = max(mx, max(max(d[i][0][0], d[i][0][1]), max(d[i][1][0], d[i][1][1])));
  }

  printf("%lld\n", mx);
}

int main() {
  int t;

  scanf("%d", &t);
  while(t--) pro();
}