#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> pi;
priority_queue<pi> Q;
int N, K, S;  
int ans;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int i, x, y, mx;

  cin >> N >> K >> S;
  for(i=1 ; i<=N ; i++) {
    cin >> x >> y;
    Q.push({x, y});
  }

  while(!Q.empty()) {
    mx = Q.top().first;
    for(i=1 ; i<=K && !Q.empty() ; i++) {
      pi tt = Q.top();
      Q.pop();
      tt.second--;
      if(tt.second>0) Q.push(tt);
    }
    ans += mx*2;
  }

  cout << ans;
}