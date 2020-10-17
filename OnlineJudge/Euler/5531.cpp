#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int d[300005], mx[300005];
pair<int, int> a[300005];

int main() {
  int i, x, y;

  cin >> N >> S;
  for(i=1 ; i<=N ; i++) cin >> a[i].first >> a[i].second;

  sort(a+1, a+N+1);
  d[N] = a[N].second;
  for(i=N-1 ; i>=1 ; i--) {
    int k = lower_bound(a+1, a+N+1, make_pair(a[i].first+S, 0)) - a;
    d[i] = a[i].second + max(d[k], mx[k]);
    mx[i] = max(d[i+1], mx[i+1]);
  }

  cout << max(d[1], mx[1]) << "\n";
}