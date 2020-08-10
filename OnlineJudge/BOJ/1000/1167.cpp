#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define max(x, y) ((x)>(y)?(x):(y))
using namespace std;

int n;
int visit[100005], dist[100005];
vector<vector<pair<int, int> > > a;
queue<int> Q;

int main() {
	int i, j, x, y, z;

	scanf("%d", &n);
	a.resize(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%d", &z);
		while (1) {
			scanf("%d", &x);
			if (x == -1) break;
			scanf("%d", &y);
			a[z].push_back({ x, y });
			a[x].push_back({ z, y });
			// printf("%d %d %d\n", x, y, z);
		}
	}

	Q.push(1);
	visit[1] = 1;
	while (!Q.empty()) {
		x = Q.front(), Q.pop();
		int len = a[x].size();
		for (i = 0; i < len; i++)
			if (visit[a[x][i].first] == 0) {
				dist[a[x][i].first] = dist[x] + a[x][i].second;
				visit[a[x][i].first] = 1;
				Q.push(a[x][i].first);
			}
	}

	int mx = 0, v;

	for (i = 1; i <= n; i++) {
		if (mx < dist[i]) mx = dist[i], v = i;
		dist[i] = visit[i] = 0;
	}
	Q.push(v);
	visit[v] = 1;
	while (!Q.empty()) {
		x = Q.front(), Q.pop();
		int len = a[x].size();
		for (i = 0; i < len; i++)
			if (visit[a[x][i].first] == 0) {
				dist[a[x][i].first] = dist[x] + a[x][i].second;
				visit[a[x][i].first] = 1;
				Q.push(a[x][i].first);
			}
	}

	mx = 0;
	for (i = 1; i <= n; i++) mx = max(mx, dist[i]);
	printf("%d", mx);
}