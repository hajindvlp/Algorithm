#include <stdio.h>
#define min(x, y) (((x)<(y))?(x):(y))

int n;
int s[4005], a[4005];

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i * 2 + 1]);
	}
	n = 2 * n + 1;

	int r, p;
	r = p = 0;
	for (i = 0; i < n; i++) {
		if (i <= r) a[i] = min(a[2 * p - i], r - i);
		else a[i] = 0;

		while (i - a[i] - 1 >= 0 && i + a[i] + 1 < n && s[i - a[i] - 1] == s[i + a[i] + 1]) a[i]++;

		if (i + a[i] > r) {
			r = i + a[i];
			p = i;
		}
	}

	scanf("%d", &n);

	while (n--) {
		int r, l, mid;
		scanf("%d %d", &l, &r);
		r = (r - 1) * 2 + 1;
		l = (l - 1) * 2 + 1;
		mid = (r + l) / 2;
		printf("%d\n", (a[mid] >= r -mid));
	}
}