#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
int n;

int main() {
  int i, x, y;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d.%d", &x, &y), a.push_back(x*1000+y);
  sort(a.begin(), a.end());
  for(i=0 ; i<7 ; i++) printf("%d.%03d\n", a[i]/1000, a[i]%1000);
}