#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, m, k, i, j;
  int a[105][105], sum[105];

  cin >> n >> m >> k;
  for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++) cin >> a[i][j];

  for(i=1 ; i<=m ; i++) 
    for(j=1 ; j<=n ; j++) {
      sum[j] += a[j][i];
      if(sum[j] >= k) {
        cout << j << " " << i << "\n";
        return 0;
      }
    }
}