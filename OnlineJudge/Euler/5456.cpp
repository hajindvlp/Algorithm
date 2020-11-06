#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
pair<int, int> a[100005], b[100005], dict[100005];

int main() {
  int i, x;
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>N;
  for(i=1 ; i<=N ; i++) cin >> x, a[i] = b[i] = {x, i};
  sort(b+1, b+N+1);
  for(i=1 ; i<=N ; i++) dict[]

  for(i=N ; i>=1 ; i--) {
    if(i != b[i].second) {
      ans += b[i].first;
      b[i].second 
    }
  }
}