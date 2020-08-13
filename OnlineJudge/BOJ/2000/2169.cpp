#include <stdio.h>
#define INF 1000000000
#define max(x, y) ((x)>(y)?(x):(y))

int n, m;
int d[1005][1005], a[1005][1005], left[1005];

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	for (i = 0; i <= n; i++) for (j = 0; j <= m; j++) d[i][j] = -INF;
	d[1][0] = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			d[i][j] = a[i][j] + max(d[i - 1][j], d[i][j - 1]);
			left[j] = -INF;
		}
		left[j] = -INF;
		if (i != 1 && i != n) {
			for (j = m; j >= 1; j--) {
				left[j] = a[i][j] + max(d[i - 1][j], left[j + 1]);
				d[i][j] = max(d[i][j], left[j]);
			}
		}
	}

	printf("%d\n", d[n][m]);
}