#include <stdio.h>
#include <string.h>
#define MAX_N 100005
#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))

char t[MAX_N], s[2*MAX_N];
int a[2*MAX_N], n, mx;

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

	for (i = 0; i < n; i++) mx = max(mx, a[i]);
	printf("%d\n", mx);
}