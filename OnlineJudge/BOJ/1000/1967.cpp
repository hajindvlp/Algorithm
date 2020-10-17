#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;

int n;
vector<vector<pii> > a;
priority_queue<pii, vector<pii>, greater<pii> > Q;

vector<int> bfs(int s) {
	vector<int> d;
	int i;

	d.resize(n + 1, INF);
	d[s] = 0;
	Q.push({ 0, s });
	while (!Q.empty()) {
		pii t = Q.top();
		Q.pop();
		int len = a[t.second].size();
		for (i = 0; i < len; i++) {
			if (d[a[t.second][i].first] > d[t.second] + a[t.second][i].second) {
				d[a[t.second][i].first] = d[t.second] + a[t.second][i].second;
				Q.push({ d[a[t.second][i].first], a[t.second][i].first });
			}
		}
	}

	return d;
}

int main() {
	int i, j;
	int x, y, z;
	int mx, v;

	scanf("%d", &n);
	a.resize(n + 1);
	for (i = 1; i <= n-1; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
		a[y].push_back({ x, z });
	}

	vector<int> d = bfs(1);
	mx = 0;
	for (i = 1; i <= n; i++) 
		if (mx < d[i]) {
			mx = d[i];
			v = i;
		}

	d = bfs(v);
	mx = 0;
	for (i = 1; i <= n; i++)
		if (mx < d[i]) 	mx = d[i];

	printf("%d\n", mx);
}