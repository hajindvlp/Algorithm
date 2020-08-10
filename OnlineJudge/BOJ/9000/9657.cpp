#include <stdio.h>

int a[1005];

int main() {
	int n, i;

	scanf("%d", &n);
	a[0] = 0;
	for (i = 1; i <= n; i++) {
		a[i] = 0;
		a[i] = a[i] || !a[i - 1];
		if (i >= 3) a[i] = a[i] || !a[i - 3];
		if (i >= 4) a[i] = a[i] || !a[i - 4];
		printf("%d ", a[i]);
	}
	printf("\n");
	a[0] = 1;
	for (i = 1; i <= n; i++) {
		a[i] = 0;
		a[i] = a[i] || !a[i - 1];
		if (i >= 3) a[i] = a[i] || !a[i - 3];
		if (i >= 4) a[i] = a[i] || !a[i - 4];
		printf("%d ", a[i]);
	}

	printf("%s", (!a[i]) ? "SK" : "CY");
}