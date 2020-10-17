#include <stdio.h>

int main() {
	int n, m, a[11];
	int i, x, y, sum = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (i = n; i >= 1; i--) if (m / a[i] > 0) sum += m / a[i], m = m % a[i];

	printf("%d\n", sum);
}