#include <iostream>
using namespace std;

bool prime[10005];

int main() {
  int a, b, i, j, mn = 10000, sum = 0;

  prime[1] = true;
  for(i=2 ; i<=10000 ; i++) 
    if(!prime[i])
      for(j=i*i ; j<=10000 ; j+=i)
        prime[j] = true;

  cin >> a >> b;
  for(i=a ; i<=b ; i++) 
    if(!prime[i]) {
      mn = min(mn, i);
      sum += i;
    }
  if(sum == 0 || mn == 10000) cout << -1;
  else cout << sum << "\n" << mn;
}