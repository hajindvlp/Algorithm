#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<long long, long long> > a;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N, M, i;
  long long x, y;
  long long sum = 0;

  cin >> N >> M;

  for(i=1 ; i<=N ; i++) {
    cin >> x >> y;
    a.push_back({y, x});
  }

  sort(a.begin(), a.end());

  for(i=0 ; i<N ; i++) {
    sum += a[i].second + (long long)(M-N+i) * a[i].first;
  }

  cout << sum;
}