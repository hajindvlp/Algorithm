#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF 1000000000

using namespace std;

int n, cnt;
int c[55], a[55][55], visit[55], mn[55];
queue<int> Q;
double ans;

int main() {
	int i, j, y;
	char t[55];

	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &c[i]), mn[i] = INF;

	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		for (j = 1; j <= n; j++) 
			if (t[j] == 'Y') a[i][j] = 1;
	}

	for (i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			cnt++;
			Q.push(i);
			while (!Q.empty()) {
				y = Q.front();
				visit[y] = cnt;
				Q.pop();
				for (i = 1; i <= n; i++) 
					if (a[y][i] && visit[i] == 0) {
						visit[i] = cnt;
						Q.push(i);
					}
			}
		}
	}

	for (i = 1; i <= n; i++) 
		if (mn[visit[i]] > c[i]) mn[visit[i]] = c[i];

	for (i = 1; i <= cnt; i++)
		ans += (double)mn[i];

	printf("%lf", ans/cnt);
}