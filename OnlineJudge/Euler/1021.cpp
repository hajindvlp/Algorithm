#include <iostream>
using namespace std;

int sum, N, mn = 100000;

int main() {
  int i, x;
  for(i=1 ; i<=7 ; i++) {
    cin >> x;
    if(x%2) sum += x, mn = min(mn, x);
  }
  if(sum!=0) cout << sum << "\n" << mn << "\n";
  else cout << -1;
}