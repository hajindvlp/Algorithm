#include <iostream>
using namespace std;

int a[100000], mx;

int main() {
  int N;

  cin >> N;
  a[1] = 1;
  for(int i=1 ; i<=N ; i++) {
    if(i%2) a[i] = a[i/2] + a[i/2+1];
    else a[i] = a[i/2];

    mx = max(a[i], mx);
  }

  cout << mx;
}