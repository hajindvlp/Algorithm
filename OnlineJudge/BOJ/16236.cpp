#include <stdio.h>
#include <queue>
#include <algorithm>
#define min(x,y) ((x)<(y)?(x):(y))
#define INF 1000000000

using namespace std;

typedef pair<int, int> pii;

int a[25][25], d[25][25];
int n, ans;
int sx, sy, ss = 2, se;
int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
queue<pii> Q;

int main() {
	int i, j;
	int yy, xx, ty, tx;
	int ey, ex, es, ed, ec = 0;

	scanf("%d", &n);
	for(i=1 ; i<=n ; i++)
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 9) sy = i, sx = j, a[i][j] = 0;
		}

	while (1) {
		for (i = 1; i <= n; i++) 
			for (j = 1; j <= n; j++) 
				d[i][j] = INF;
		ey = ex = ed = INF;

		d[sy][sx] = 0;
		Q.push({ sy, sx });
		while (!Q.empty()) {

			yy = Q.front().first;
			xx = Q.front().second;
			Q.pop();

			for (i = 0; i < 4; i++) {
				ty = yy + dy[i];
				tx = xx + dx[i];
				if (ty > 0 && ty <= n && tx>0 && tx <= n && a[ty][tx] <= ss && d[ty][tx] > d[yy][xx] + 1) {
					d[ty][tx] = d[yy][xx] + 1;
					Q.push({ ty, tx });
					if (a[ty][tx] != 0 && a[ty][tx] < ss && ed >= d[yy][xx] + 1) {
						if (ed > d[ty][tx]) {
							ed = d[ty][tx];
							ey = ty;
							ex = tx;
						}
						else if (ed == d[ty][tx]) {
							if (ey > ty) ey = ty, ex = tx;
							else if (ey == ty && ex > tx) ex = tx;
						}
					}
				}
			}
		}
		if (ed >= INF) break;
		else {
			ec++;
			a[ey][ex] = 0;
			sy = ey, sx = ex;
			if (ec == ss) {
				ss++, ec = 0;
			}
		}
		ans+=ed;
	}
	printf("%d", ans);
}