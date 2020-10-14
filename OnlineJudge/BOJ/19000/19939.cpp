#include <iostream>
using namespace std;

int main() {
  int N, K;
  
  cin >> N >> K;
  if(N < K * (K+1) / 2) cout << -1;
  else cout << (( N - K * (K+1) / 2 ) % K != 0 ) + K-1;
}