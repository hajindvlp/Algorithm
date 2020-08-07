#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii> > a;
priority_queue<pii, vector<pii>, greater<pii> > Q;
int n, m;
int s, e;
int d[1005];

int main() {
	int x, y, z, ty, tx, len;
	int i, j;

	scanf("%d %d", &n, &m);
	a.resize(n + 1);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
	}
	scanf("%d %d", &s, &e);

	for (i = 1; i <= n; i++) d[i] = INF;

	Q.push({ 0, s });
	d[s] = 0;
	while (!Q.empty()) {
		x = Q.top().first;
		y = Q.top().second;
		Q.pop();
		len = a[y].size();
		for (i = 0; i < len; i++) {
			if (d[a[y][i].first] > d[y] + a[y][i].second) {
				d[a[y][i].first] = d[y] + a[y][i].second;
				Q.push({ d[y] + a[y][i].second, a[y][i].first });
			}
		}
	}

	printf("%d\n", d[e]);
}