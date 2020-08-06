#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > a;
int visit[1005], d[1005], dur[1005];

int f(int n) {
	int i;

	if (visit[n]) return d[n];
	else {
		int len = a[n].size(), mx = 0;
		visit[n] = 1;
		for (i = 0; i < len; i++) mx = max(mx, f(a[n][i]));
		return d[n] = mx + dur[n];
	}
}

void pro() {
	int n, m, e;
	int i, j, x, y;

	a.clear();
	for (i = 1; i <= 1000; i++) dur[i] = d[i] = visit[i] = 0;

	scanf("%d %d", &n, &m);
	a.resize(n + 1);
	for (i = 1; i <= n; i++) scanf("%d", &dur[i]);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		a[y].push_back(x);
	}
	scanf("%d", &e);

	printf("%d", f(e));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) pro();
}