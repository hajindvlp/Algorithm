#include <stdio.h>
#define INF 1000000000

int d[505][505], v[505][505], sum[505];
int a[505], n;

int f(int s, int e) {
	if (s >= e) return 0;
	if (s + 1 == e) return a[s] + a[e];
	if (v[s][e]) return d[s][e];
	else {
		int mn = INF, i, t;
		for (i = s; i < e; i++) {
			t = f(s, i) + f(i + 1, e);
			if (mn > t) mn = t;
		}
		v[s][e] = 1;
		return d[s][e] = mn + sum[e]-sum[s-1];
	}
}

void pro() {
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) d[i][j] = v[i][j] = 0;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]), d[i][i] = a[i], sum[i] = sum[i-1] + a[i], v[i][i] = 1;

	printf("%d\n", f(1, n));
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) pro();
}