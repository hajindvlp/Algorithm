#include <iostream>
using namespace std;

unsigned long long N, a[1000005], mx, ans, i;

int main() {
  int j;
  unsigned long long zcnt, ocnt;

  cin >> N;
  for(i=1 ; i<=N ; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }

  for(i=1 ; i/2<=2*mx ; i*=2) {
    zcnt = ocnt = 0;
    for(j=1 ; j<=N ; j++) 
      if(a[j]&i) ocnt++;
    zcnt = N-ocnt;
    ans += zcnt * ocnt * i;
  }

  cout << ans << "\n";
}