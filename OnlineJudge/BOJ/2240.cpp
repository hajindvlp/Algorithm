#include <stdio.h>

int n, m;
int d[35][1005], s[2][1005];

int max(int x, int y) {
	return (x > y) ? x : y;
}

int main() {
	int i, j, x, mx = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &x);

		for (j = 1; j <= m+1; j++) {
			d[j][i] = max(d[j - 1][i - 1] + (j % 2 == x % 2), d[j][i - 1] + (j % 2 == x % 2));
		}
	}

	for (i = 1; i <= m + 1; i++) mx = max(mx, d[i][n]);
	printf("%d\n", mx);
}