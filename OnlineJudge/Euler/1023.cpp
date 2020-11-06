#include <iostream>
#include <algorithm>
using namespace std;

int N, a[105];
int mn, mx;

int main() {
  int i;
  cin>>N;
  for(i=1;i<=N;i++) cin >> a[i];
  mn = mx = a[1];
  for(i=2;i<=N;i++) mn = min(mn, a[i]), mx=max(mx, a[i]);
  cout << mx << "\n" << mn;
}