#include <stdio.h>
#include <string.h>
#define INF 1000000000
#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))

char t[2505], s[5010];
int a[5010], d[5010];
int n, mx;

int main() {
	int i, j;
	int p, r;

	scanf("%s", t);
	n = strlen(t);
	for (i = 0; i < n; i++) s[i * 2] = '#', s[i * 2 + 1] = t[i];
	s[i * 2] = '#';

	n = 2 * n + 1;
	p = r = 0;

	for (i = 0; i < n; i++) {
		if (i <= r) a[i] = min(a[2 * p - i], r - i);
		else a[i] = 0;

		while (i + a[i] + 1 < n && i - a[i] - 1 >= 0 && s[i + a[i] + 1] == s[i - a[i] - 1]) a[i]++;

		if (i + a[i] > r) {
			p = i;
			r = i + a[i];
		}
	}

	for (i = 0; i < n; i++) printf("%d ", a[i]);

	for (i = 0; i < n; i++) d[i] = INF;

	d[0] = 1;
	for (i = 1; i < n; i++) {
		if (i % 2 == 0) {
			for (j = 1; j <= a[i] / 2; j++) {

			}
				if (d[i / 2 - 1 + j] > d[i / 2 - j] + 1)
					d[i / 2 - 1 + j] = d[i / 2 - j] + 1;
		}
		else {
			for (j = 0; j <= a[i] / 2; j++) {
				if((i-1)/2 + j)
			}
				if (d[(i - 1) / 2 + j] > d[(i - 1) / 2 - j] + 1)
					d[(i - 1) / 2 + j] > d[(i - 1) / 2 - j] + 1;
		}
	}

	for (i = 0; i < n; i++) mx = max(mx, a[i]);
	printf("%d\n", mx);
}