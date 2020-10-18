#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
  int N, i, j;
  double rLen, lLen, len;
  pair<double, double> a[5];

  cin >> N;
  len = N;
  for(i=1 ; i<=3 ; i++) cin >> a[i].first >> a[i].second;
  
  for(i=1 ; i<=3 ; i++) {
    double mid = (a[i].first + a[i].second)/2;
    if(a[i].first == a[i].second) continue;
    lLen = mid;
    rLen = len-mid;
    len = max(lLen, rLen);;
    for(j=i+1 ; j<=3 ; j++) a[j] = {abs(a[j].first-mid),abs(a[j].second-mid)};
  }

  cout << fixed << setprecision(1) << len;
}