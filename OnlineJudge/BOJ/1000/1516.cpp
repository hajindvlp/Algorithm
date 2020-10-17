#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > a;
int d[505], visit[505], dur[505];
int n;

int f(int x) {
	if (visit[x]) return d[x];
	int len = a[x].size(), mx = 0, i;
	visit[x] = 1;
	for (i = 0; i < len; i++) mx = max(mx, f(a[x][i]));
	return d[x] = mx + dur[x];
}

int main() {
	int i, j;
	int x, y;

	scanf("%d", &n);
	a.resize(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%d", &dur[i]);
		while (1) {
			scanf("%d", &x);
			if (x == -1) break;
			a[i].push_back(x);
		}
	}

	for (i = 1; i <= n; i++) printf("%d\n", f(i));
}