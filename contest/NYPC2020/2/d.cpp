#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n, m;
int a[1005][1005], visit[1005][1005];
int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
queue<pii> Q;

void mn() {
	int i, j, k, cnt = 0;
	int ty, tx;
	for (i = 1; i <= n; i++) 
		for (j = 1; j <= m; j++) 
			if (visit[i][j] == 0 && a[i][j] == 0) {
				visit[i][j] = ++cnt;
				Q.push({ i, j });
				while (!Q.empty()) {
					pii t = Q.front(); Q.pop();
					for (k = 0; k < 4; k++) {
						ty = t.first + dy[k];
						tx = t.second + dx[k];
						if (ty > 0 && ty <= n && tx > 0 && tx <= m && a[ty][tx] != -1 && visit[ty][tx] == 0) {
							visit[ty][tx] = cnt;
							Q.push({ ty, tx });
						}
					}
				}
			}
	printf("%d\n", cnt);
}

void mx() {

}

int main() {
	int i, j;
	char s[1005], t[5];

	scanf("%d %d ", &n, &m);
	scanf("%s", &t[1]);
	for (i = 1; i <= n; i++) {
		scanf("%s", &s[1]);
		for (j = 1; j <= m; j++) {
			if (s[j] == 'S') a[i][j] = -1;
			else if (s[j] == '?') a[i][j] = 1;
		}
	}
	if (t[3] == 'x') mx();
	else mn();

}