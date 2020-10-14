#include <iostream>
#define MOD 1000000007
using namespace std;

int N;

long long pow(long long x, int y) {
  long long on = x;

  while(y--) {
    on = (on * x) % MOD;
  }

  return on;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long i, x, y, sum = 0, m;

  cin >> N >> m;
  for(i=1 ; i<=N+1 ; i++) {
    cin >> x >> y;
    sum = (sum + x * pow(m, y-1)) % MOD;
  }

  cout << sum;
}