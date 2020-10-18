#include <iostream>
using namespace std;

void pro() {
  int sy, sx, ey, ex;

  cin >> sy >> sx >> ey >> ex;
  if(sy == ey) cout << abs(sx-ex);
  else if(sx == ex) cout << abs(ey - sy);
  else {
    cout << abs(ey-sy) + 2 + abs(ex-sx);
  }
  cout << "\n";
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) pro();
}