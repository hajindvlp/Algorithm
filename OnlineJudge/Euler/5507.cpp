#include <iostream>
#include <numeric>
using namespace std;

void pro(int idx) {
  unsigned long long m, w, d, iv, ivRows, ivMths, remMths, ans;
  unsigned long long normalWeek, endWeek;
  m = w = d = iv = ivRows = ivMths = remMths = ans = 0;
  normalWeek = endWeek = 0;

  cin >> m >> w >> d;

  endWeek = w/d + (w%d!=0);
  normalWeek = endWeek+1;

  iv = lcm(w, d); 
  ivMths = iv/w;
  ivRows = iv/d + ivMths - 1; 
  remMths = m % ivMths;

  ans = (m/ivMths) * ivRows;
  if(remMths != 0)  
    ans += (remMths-1)*normalWeek + endWeek;
  cout << "Case #" << idx << ": " << ans << "\n";  
}

int main() {
  int t, cnt = 0;

  cin >> t;
  while(t--) pro(++cnt);
}