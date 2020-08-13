#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int n, m, sum;
int d[1005], visit[1005];
vector<vector<pair<int, int> > > a;

int main() {
	int x, y, z;
	int i, j, v;

	scanf("%d %d", &n, &m);
	a.resize(n + 1);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
		a[y].push_back({ x, z });
	}

	for (i = 1; i <= n; i++) d[i] = INF;
	d[1] = 0;

	for (i = 1; i <= n; i++) {
		int mn = INF;
		for (j = 1; j <= n; j++)
			if (visit[j] == 0 && d[j] < mn) {
				mn = d[j];
				v = j;
			}
		visit[v] = 1;
		sum += mn;

		int len = a[v].size();
		for (j = 0; j < len; j++)
			if (visit[a[v][j].first] == 0 && d[a[v][j].first] > a[v][j].second)
				d[a[v][j].first] = a[v][j].second;
	}

	printf("%d\n", sum);
}