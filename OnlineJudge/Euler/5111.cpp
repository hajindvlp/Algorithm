#include <iostream>
#define MM 1505
using namespace std;

int N, M, K, ans;
int sum[MM][MM], a[MM][MM], dp[4][MM][MM], mx[4][MM][MM];

int main() {
  int i, j, k;

  cin >> N >> M >> K;
  for(i=1 ; i<=N ; i++) for(j=1 ; j<=M ; j++) {
    cin >> a[i][j];
    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
  }

  for(k=1 ; k<=3 ; k++) 
    for(i=K ; i<=N ; i++) 
      for(j=K ; j<=M ; j++) {
        dp[k][i][j] = sum[i][j] - sum[i-K][j] - sum[i][j-K] + sum[i-K][j-K] + max(mx[k-1][i-K][M], mx[k-1][i][j-K]);
        mx[k][i][j] = max(max(mx[k][i-1][j], mx[k][i][j-1]), dp[k][i][j]);
      }

  cout << mx[K][N][M];
}