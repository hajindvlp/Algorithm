#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n, m, sy, sx;
int dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0, 1, 0, -1 };
int d[105][105];
pair<int, int> path[10005];

void rec(int y, int x, int lev) {
	int i, j;
	if (lev == n * m ) {
		for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) path[d[i][j]] = make_pair(i, j);
		for (i = 1; i <= n * m; i++) printf("%d %d\n", path[i].first, path[i].second);
		exit(0);
	}

	for (i = 1; i <= m; i++) if (d[y][i] == 0) {
		d[y][i] = lev + 1;
		rec(y, i, lev + 1);
		d[y][i] = 0;
	}
	for (i = 1; i <= n; i++) if (d[i][x] == 0) {
		d[i][x] = lev + 1;
		rec(i, x, lev + 1);
		d[i][x] = 0;
	}
}

int main() {
	int i, j;

	scanf("%d %d %d %d", &n, &m, &sy, &sx);

	d[sy][sx] = 1;
	rec(sy, sx, 1);
}