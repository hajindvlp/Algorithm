#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, i, x;
  int fm, sm;
  bool isN = false;

  fm = sm = 1000000000;
  cin >> n;
  for(i=1 ; i<=n ; i++) {
    cin >> x;
    if(x == -1) isN = true;
    else {
      if(!isN) fm = min(fm, x);
      else sm = min(sm, x);
    }
  }
  cout << sm + fm;
}