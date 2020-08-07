#include <stdio.h>

int n, a[2005], d[2005][2005];

int main() {
	int i, j, k;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[i][i] = 1;
		if (a[i] == a[i - 1]) d[i - 1][i] = 1;
	}

	for (k = 2; k < n; k++) 
		for (i = 1; i <= n-k; i++) {
			int j = i + k;

			d[i][j] = d[i + 1][j - 1] && (a[i] == a[j]);
		}

	scanf("%d", &n);
	while (n--) scanf("%d %d", &i, &j), printf("%d\n", d[i][j]);
}