#include <stdio.h>

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
const int n_ = 500 + 5;

int n, a[n_][n_], dp[n_][n_];

inline int max(int a, int b) { return a > b ? a : b; }

int dfs(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (a[x][y] < a[nx][ny])
			dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	return dp[x][y];
}

int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
		scanf("%d", &a[i][j]);

	int ans = 0;
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
		ans = max(ans, dfs(i, j));

	printf("%d", ans);

	return 0;
}
