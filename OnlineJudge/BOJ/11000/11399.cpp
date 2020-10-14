#include <iostream>
#include <algorithm>
using namespace std;

int a[1005], n, sum, dur;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int i;
  cin >> n;
  for(i=1 ; i<=n ; i++) cin >> a[i];
  sort(a+1, a+n+1);
  for(i=1 ; i<=n ; i++) dur += a[i], sum += dur; 

  printf("%d\n",sum);
}