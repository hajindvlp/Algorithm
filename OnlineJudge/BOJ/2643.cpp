#include <stdio.h>
#include <algorithm>

using namespace std;

pair<int, int> p[101];
int n, d[101], mx;

int main() {
  int i, j, x, y;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) {
    scanf("%d %d", &x, &y);
    if(x < y) p[i] = make_pair(x, y);
    else p[i] = make_pair(y, x);
  }
  sort(p+1, p+n+1);

  for(i=1 ; i<=n ; i++) 
    for(j=0 ; j<=i-1 ; j++) 
      if(p[j].first <= p[i].first && p[j].second <= p[i].second && d[i] < d[j]+1)
        d[i] = d[j]+1;

  for(i=1 ; i<=n ; i++)
    if(d[i] > mx)
      mx = d[i];

  printf("%d", mx);
}