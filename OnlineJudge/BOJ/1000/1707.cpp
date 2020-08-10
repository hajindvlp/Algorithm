#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void pro() {
	vector<vector<int> > a;
	queue<int> Q;
	int visit[20005];
	int n, m, cnt, x, y, len;
	int i, j;

	a.clear();
	cnt = 0;
	for (i = 1; i <= 20000; i++) visit[i] = 0;

	scanf("%d %d", &n, &m);
	a.resize(n + 1);

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}

	for (i = 1; i <= n; i++) visit[i] = -1;
	
	for (i = 1; i <= n; i++) {
		if (visit[i] == -1) {
			Q.push(i);
			visit[i] = 1;
			while (!Q.empty()) {
				y = Q.front();
				Q.pop();
				len = a[y].size();
				for (j = 0; j < len; j++) {
					if (visit[a[y][j]] == -1) {
						visit[a[y][j]] = 1 - visit[y];
						Q.push(a[y][j]);
					}
					else if (visit[a[y][j]] == visit[y]) {
						printf("NO\n");
						return;
					}
				}
			}

		}
	}
	
	printf("YES\n");
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) pro();
}