#include <iostream>
#include <algorithm>
using namespace std;

int N, a[105];

int main() {
  int i;
  for(i=1;i<=10;i++) cin >> a[i];
  sort(a+1, a+10+1);
  cout << a[8];
}