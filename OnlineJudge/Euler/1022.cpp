#include <iostream>
#include <algorithm>
using namespace std;

int N, a[105];

int main() {
  int i;
  cin>>N;
  for(i=1;i<=N;i++) cin >> a[i];
  for(i=1;i<=N;i++) cout << a[i] << " ";
  cout << "\n";
  sort(a+1, a+N+1);
  for(i=1;i<=N;i++) cout << a[i] << " ";
}