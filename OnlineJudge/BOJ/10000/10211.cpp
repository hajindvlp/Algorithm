#include <stdio.h>

void pro() {
	int n, i, j;
	int x, d[1005], mx;

	for (i = 0; i <= 1000; i++) d[i] = 0;
	
	scanf("%d", &n);
	mx = -1000000000;
	for (i = 1; i <= n; i++) {
		scanf("%d", &x);
		d[i] = d[i - 1] + x;
		for (j = 0; j < i; j++) if (d[i] - d[j] > mx) mx = d[i] - d[j];
	}
	printf("%d\n", mx);
}

int main() {
	int N;

	scanf("%d", &N);
	while (N--) pro();
}