#include <stdio.h>

int n;
int a[40][40];
long long d[3][40][40];

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);

	d[0][1][2] = 1;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (a[i][j] == 0) {
				d[0][i][j] += d[0][i][j - 1] + d[2][i][j - 1];
				d[1][i][j] += d[1][i - 1][j] + d[2][i - 1][j];
			}

			if (a[i][j] == 0 && a[i - 1][j] == 0 && a[i][j - 1] == 0) {
				d[2][i][j] += d[0][i - 1][j - 1] + d[1][i - 1][j - 1] + d[2][i - 1][j - 1];
			}
		}
	}

	printf("%llu\n", d[0][n][n] + d[1][n][n] + d[2][n][n]);
}