#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF 1000000000
#define abs(x) ((x)>0?(x):-(x))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;

typedef pair<int, int> pii;

queue<pii> Q;
int n, m, t;
int a[105][105], d[105][105], dist;
int sx, sy;
int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };

int main() {
	int i, j;
	int yy, xx, ty, tx;

	scanf("%d %d %d", &n, &m, &t);

	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
		d[i][j] = INF;
		scanf("%d", &a[i][j]);
		if (a[i][j] == 2) sy = i, sx = j;
	}

	d[1][1] = 0;
	Q.push({ 1, 1 });
	while (!Q.empty()) {
		yy = Q.front().first;
		xx = Q.front().second;
		Q.pop();
		for (i = 0; i < 4; i++) {
			ty = yy + dy[i];
			tx = xx + dx[i];
			if (ty > 0 && ty <= n && tx > 0 && tx <= m && a[ty][tx] != 1 && d[ty][tx] > d[yy][xx] + 1) {
				d[ty][tx] = d[yy][xx] + 1;
				Q.push({ ty, tx });
			}
		}
	}

	dist = min(d[n][m], d[sy][sx] + abs(n - sy) + (m - sx));
	if (dist <= t) printf("%d", dist);
	else printf("Fail");
}