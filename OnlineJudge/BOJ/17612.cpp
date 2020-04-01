#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<pair<int, int>, int> Cart;
typedef pair<int, int> Line;

int n, m;
priority_queue<Line, vector<Line>, greater<Line> > WaitQueue;
priority_queue<Cart, vector<Cart>, greater<Cart> > OutQueue;
int cnt;
long long int ans;

int main() {
  int i, x, y;
  Line TLine;

  scanf("%d %d", &n, &m);

  for(i=1 ; i<=m ; i++) {
    TLine = make_pair(0, i);
    WaitQueue.push(TLine);
  }

  for(i=1 ; i<=n ; i++) {
    scanf("%d %d", &x, &y);

    TLine = WaitQueue.top(), WaitQueue.pop();
    TLine.first+=y;
    WaitQueue.push(TLine);
    OutQueue.push(make_pair(make_pair(TLine.first, m-TLine.second), x));
  }

  while(!OutQueue.empty()) ans += 1LL * OutQueue.top().second * (++cnt), OutQueue.pop();
  printf("%lld", ans);
}