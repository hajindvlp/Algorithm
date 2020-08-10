#include <stdio.h>

int a[15];

int main() {
	int n, i;

	a[1] = 0;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			a[i] = (i / 2) * (i / 2) + 2 * a[i / 2];
		}
		else {
			a[i] = (i / 2) * (i / 2 + 1) + a[i / 2] + a[i / 2 + 1];
		}
	}
	printf("%d", a[n]);
}