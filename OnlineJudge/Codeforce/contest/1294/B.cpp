#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void pro() {
  int n;
  int i, j, x, y;
  vector<pair<int, int> > a;
  int rcnt, ucnt;

  scanf("%d", &n);
  a.push_back(make_pair(0, 0));
  for(i=1 ; i<=n ; i++) scanf("%d %d", &x, &y), a.push_back(make_pair(x, y));
  sort(a.begin(), a.end());

  for(i=1 ; i<=n ; i++) if(!(a[i].first >= a[i-1].first && a[i].second >= a[i-1].second)) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for(i=1 ; i<=n ; i++) {
    rcnt = a[i].first-a[i-1].first;
    ucnt = a[i].second-a[i-1].second;

    for(j=1 ; j<=rcnt ; j++) printf("R");
    for(j=1 ; j<=ucnt ; j++) printf("U");
  }
  printf("\n");
  return;
}

int main() {
  int k;
  
  scanf("%d", &k);

  while(k--) pro(); 
}