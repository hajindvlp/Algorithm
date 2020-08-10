#include <stdio.h>

int n, s[1030][1030], m;

int main() {
	int x, y, z, w, i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) scanf("%d", &x), s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &x, &y, &z, &w);
		printf("%d\n", s[z][w] - s[x - 1][w] - s[z][y - 1] + s[x - 1][y - 1]);
	}
}