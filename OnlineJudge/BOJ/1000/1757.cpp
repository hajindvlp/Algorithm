#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;

int n, m;
int d;
int dp[501][10005];

int main() {
	int i, j;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		scanf("%d", &d);
		dp[0][i] = dp[0][i - 1];
		for (j = 1; j <= m && j <= i; j++) dp[0][i] = max(dp[0][i], dp[j][i - j]);
		for (j = 1; j <= m && j<=i; j++)
			dp[j][i] = dp[j - 1][i - 1] + d;
	}

	printf("%d\n", dp[0][n]);
}