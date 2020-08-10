#include <stdio.h>

int n, a[55][55];
int d;

int leaf(int k) {
	int i, sum = 0;

	for (i = 0; i < n; i++) 
		if (a[k][i]) sum += leaf(i);
	if (sum == 0) return 1;
	return sum;
}

int main() {
	int i, x, p;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == -1) x = p;
		else a[x][i] = 1;
	}
	scanf("%d", &d);
	for (i = 0; i < n; i++)
		a[i][d] = 0;

	if (p == d) printf("0");
	else printf("%d", leaf(p));
}