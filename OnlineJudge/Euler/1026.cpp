#include <iostream>
using namespace std;

int main() {
  int a[7], b[7] = {0, 1, 1, 2, 2, 2, 8};

  for(int i=1 ; i<=6 ; i++) cin >> a[i];
  for(int i=1 ; i<=6 ; i++) cout << b[i]-a[i] << " ";
}