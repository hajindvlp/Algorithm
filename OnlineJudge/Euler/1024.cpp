#include <iostream>
using namespace std;

int ans;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if(a==b && b==c) ans = 10000 + a*1000;
  else if(a==b) ans = 1000+a*100;
  else if(c==b) ans = 1000+b*100;
  else if(a==c) ans = 1000+a*100;
  else ans = max(max(a, b), c) *100;

  cout << ans;
}