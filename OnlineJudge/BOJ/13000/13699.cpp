#include <stdio.h>
long long int  a[40];

int main() {
	int i, j;
	int n;

	a[0] = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 0; j < i; j++)
			a[i] += a[j] * a[i - j - 1];
	printf("%lld\n", a[n]);
}