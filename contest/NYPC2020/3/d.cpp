#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii> > Q;
vector<vector<pii> > a;
int n, m, k, s, cnt;

int main() {
	int i, j;
	int x, y, z;

	scanf("%d %d %d %d", &n, &m, &k, &s);
	a.resize(n + 1);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
	}

	Q.push({ 0, s });
	while (!Q.empty()) {
		cnt++;
		if (cnt == k) {
			printf("%d\n", Q.top().first);
			return 0;
		}

		pii t = Q.top(); Q.pop();
		int len = a[t.second].size();
		for (i = 0; i < len; i++) 
			Q.push({ a[t.second][i].second + t.first, a[t.second][i].first });
	}

	printf("-1");
}