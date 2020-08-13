#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

typedef pair<int, pair<int, int> > piii;

priority_queue<piii, vector<piii>, greater<piii> > Q;
int n, m;
int a[105][105], d[105][105];
int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };

int main() {
	int i, j;
	char t[105];

	scanf("%d %d", &m, &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		for (j = 1; j <= m; j++) {
			d[i][j] = INF;
			if (t[j] == '1') 
				a[i][j] = 1;
		}
	}

	d[1][1] = 0;
	Q.push({ 0, {1, 1} });
	while (!Q.empty()) {
		piii t = Q.top();
		Q.pop();
		int ff = t.first;
		int yy = t.second.first;
		int xx = t.second.second;
		for (i = 0; i < 4; i++) {
			int ty = yy + dy[i];
			int tx = xx + dx[i];
			if (ty > 0 && ty <= n && tx > 0 && tx <= m && d[ty][tx] > d[yy][xx] + a[ty][tx]) {
				d[ty][tx] = d[yy][xx] + a[ty][tx];
				Q.push({ d[ty][tx], {ty, tx} });
			}
		}
	}

	printf("%d", d[n][m]);
}