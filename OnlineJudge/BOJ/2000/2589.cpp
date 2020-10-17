#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int n, m, mx, cnt;
int a[51][51], d[51][51];
int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
queue<pair<int, int> > Q;

void bfs(int sy, int sx) {
	int i, j;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) 
			d[i][j] = INF;
	d[sy][sx] = 0;

	Q.push({ sy, sx });
	while (!Q.empty()) {
		pair<int, int> t = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++) {
			int ty = t.first + dy[i];
			int tx = t.second + dx[i];
			if (ty > 0 && ty <= n && tx > 0 && tx <= m && a[ty][tx] && d[ty][tx] > d[t.first][t.second] + 1) {
				d[ty][tx] = d[t.first][t.second] + 1;
				Q.push({ ty, tx });
			}
		}
	}

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (d[i][j] < INF && mx < d[i][j])
				mx = d[i][j];
}

int main() {
	int i, j;
	char t[55];

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		for (j = 1; j <= m; j++) 
			if (t[j] == 'L') a[i][j] = 1;
	}

	for(i=1 ; i<=n ; i++) 
		for (j = 1; j <= m; j++) 
			if(a[i][j])
				bfs(i, j);

	printf("%d\n", mx);
}