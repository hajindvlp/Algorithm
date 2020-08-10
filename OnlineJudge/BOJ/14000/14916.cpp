#include <stdio.h>
#define INF 1000000000

int a[100005];

int main() {
	int n, i;

	scanf("%d", &n);
	for (i = 1; i <= 100000; i++) a[i] = INF;
	for (i = 2; i <= n; i++) {
		if (a[i - 2] < INF && a[i - 2] + 1 < a[i]) a[i] = a[i - 2] + 1;
		if (i >= 5 && a[i - 5] < INF && a[i - 5] + 1 < a[i]) a[i] = a[i - 5] + 1;
	}

	if (a[n] >= INF) printf("-1");
	else printf("%d", a[n]);
}