#include <stdio.h>

int n, a[2005];
bool isP[2005][2005], v[2005][2005];

bool f(int s, int e) {
	if (s >= e) return true;
	else if (v[s][e]) return isP[s][e];
	else {
		v[s][e] = true;
		if (a[s] != a[e]) return isP[s][e] = false;
		else return isP[s][e] = f(s + 1, e - 1);
	}
}

int main() {
	int i, m, x, y, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]), isP[i][i] = true;

	for (i = 1; i < n; i++) for (j = i + 1; j <= n; j++) f(i, j);

	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", isP[x][y]);
	}
}