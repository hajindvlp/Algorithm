#include <stdio.h>
#define INF 1000000000

int n, m;
int a[105][105];

int main() {
	int i, j, k;
	int x, y, z;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) a[i][j] = INF;
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (a[x][y] > z) a[x][y] = z;
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j]; 

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (a[i][j] >= INF || i == j) printf("0 ");
			else printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}