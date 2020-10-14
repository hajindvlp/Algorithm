#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, mx;
int a[20][20], dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
vector<pair<int, int> > v, ans;

void rec(int r, int c, int lev) {
	int i, j;
	if (c == N) r++, c = 1;
	if (r >= N + 1) {
		if (lev > mx) {
			mx = lev;
			ans = v;
		}
	}
	else {
		for (i = c; i <= N; i++) 
			if (a[r][i] == 0) {
				bool flag = true;
				for (j = 0; j < 8; j++) {
					int ty = r + dy[j];
					int tx = i + dx[j];
					if (ty > 0 && ty <= N && tx > 0 && tx <= N && a[ty][tx] == 1) 
						flag = false;
				}
				if (flag) {
					v.push_back({ r, i });
					a[r][i] = 1;
					rec(r, i, lev + 1);
					a[r][i] = 0;
					v.pop_back();
				}
			}
		rec(r + 1, 1, lev);
	}
}

int main() {
	int i, j;
	int x, y;

	scanf("%d %d", &N, &M);
	while (M--) scanf("%d %d", &x, &y), a[x][y] = -1;

	rec(1, 1, 0);

	printf("%d\n", mx);
	for (i = 0; i < mx; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}