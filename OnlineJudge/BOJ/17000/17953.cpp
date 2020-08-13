#include <stdio.h>
#include <algorithm>
using namespace std;

int d[11][100005], a[11][100005];
int n, m;
int mx1, mx2, id1, id2;

int main() {
	int i, j;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (j == id1) d[j][i] = max(mx1 + a[j][i] / 2, mx2 + a[j][i]);
			else d[j][i] = mx1 + a[j][i];
		}

		for (j = 1; j <= m; j++) 
			if (mx1 < d[j][i]) mx1 = d[j][i], id1 = j;

		for (j = 1; j <= m; j++)
			if (mx2 < d[j][i] && j != id1) mx2 = d[j][i], id2 = j;
	}

	printf("%d\n", mx1);
}