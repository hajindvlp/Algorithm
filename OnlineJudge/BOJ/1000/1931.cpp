#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt;
pair<int, int> a[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, x, y;

  cin >> n;
  for(i=1;i<=n;i++) {
    cin >> x >> y;
    a[i] = {y, x};
  }
  sort(a+1, a+n+1);
  x = 0;
  for(i=1;i<=n;i++) 
    if(a[i].second>=x) {
      cnt++;
      x = a[i].first;
    }

  cout << cnt << "\n";
}