#include <stdio.h>

int n, m, sum;
int a[105];

int main() {
	int i, j, k;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= n - 2; i++) 
		for (j = i + 1; j <= n - 1; j++)
			for (k = j + 1; k <= n; k++) 
				if (a[i] + a[j] + a[k] > sum && a[i] + a[j] + a[k]<=m) sum = a[i] + a[j] + a[k];

	printf("%d", sum);
}