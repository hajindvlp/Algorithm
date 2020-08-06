#include <stdio.h>

int p[55], t[55];

int main() {
	int n, m, nt, np, ans;
	int i, j, x;

	scanf("%d %d", &n, &m);
	scanf("%d", &nt);
	for (i = 1; i <= nt; i++) scanf("%d", &t[i]);

	ans = m;
	for (i = 1; i <= m; i++) {
		scanf("%d", &np);
		for (j = 1; j <= n; j++) p[j] = 0;
		for (j = 1; j <= np; j++) scanf("%d", &x), p[x] = 1;
		for (j = 1; j <= nt; j++)
			if (p[t[j]]) {
				ans--;
				break;
			}
	}
	printf("%d", ans);
}