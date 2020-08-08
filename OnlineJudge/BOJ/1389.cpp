#include <stdio.h>
#define INF 1000000000

int n, m;
int a[105][105];

int main() {
	int i, j, k;
	int x, y;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) a[i][j] = INF;
	for (i = 1; i <= m; i++) scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];

	m = INF;
	for (i = 1; i <= n; i++) {
		k = 0;
		for (j = 1; j <= n; j++)
			if (i != j) k += a[i][j];
		if (m > k) m = k, y = i;
	}

	printf("%d", y);
}