#include <stdio.h>

int n, m, tn;
int p[101][101], t[101], e[101];

int main() {
	int i, j;
	int x, y;

	scanf("%d %d", &n, &m);

	scanf("%d", &tn);
	for (i = 1; i <= tn; i++) scanf("%d", &t[i]);

	for (i = 1; i <= m; i++) {
		scanf("%d", &x);
		for (j = 1; j <= x; j++) scanf("%d", &y), p[i][y] = 1;
	}
	
	for (i = 1; i <= tn; i++) for (j = 1; j <= m; j++) {
		if (p[j][t[i]]) t[j] = 1;
	}



}