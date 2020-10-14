#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int d[105][105][105], visit[105][105][105];
pair<int, int> pre[105][105][105];

bool rec(int a, int b, int c) {
	if (visit[a][b][c]) return d[a][b][c];
	else {
		int i;
		for (i = 0; i < a; i++) if (!rec(i, b, c)) {
			visit[a][b][c] = 1;
			pre[a][b][c] = { 1, i + 1 };
			return d[a][b][c] = 1;
		}
		for (i = 0; i < b; i++) if (!rec(min(a, i), i, c)) {
			visit[a][b][c] = 1;
			pre[a][b][c] = { 2, i + 1 };
			return d[a][b][c] = 1;
		}
		for (i = 1; i < c; i++) if (!rec(min(a, i), min(b, i), i )) {
			visit[a][b][c] = 1;
			pre[a][b][c] = { 3, i + 1 };
			return d[a][b][c] = 1;
		}
		visit[a][b][c] = 1;
		return d[a][b][c] = 0;
	}
}

int main() {
	int x, y;
	int i, j, k;
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	d[0][0][1] = 0;
	rec(a, b, c);

	while (1) {
		printf("%d %d\n", pre[a][b][c].first, pre[a][b][c].second);
		fflush(stdout);
		x = pre[a][b][c].first, y = pre[a][b][c].second;
		if (x == 1) a = y - 1;
		else if (x == 2) a = min(a, y - 1), b = y - 1;
		else a = min(a, y - 1), b = min(b, y - 1), c = y - 1;
		scanf("%d %d", &x, &y);
		if (x == 1) a = y - 1;
		else if (x == 2) a = min(a, y - 1), b = y - 1;
		else a = min(a, y - 1), b = min(b, y - 1), c = y - 1;

		if (x == 3 && y == 1) break;
	}
}