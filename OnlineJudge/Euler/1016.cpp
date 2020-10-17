#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if(a%2 == 1 && b%2 == 0) cout << 0;
  else cout << 1;
}