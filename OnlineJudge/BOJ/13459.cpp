#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
	pair<int, int> r;
	pair<int, int> b;
	bool isR = false;
	bool isB = false;
	int cnt = 0;
} board;

int a[15][15];
int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
int n, m;
board init;

void dfs(board b) {
	int i, j;

}

int main() {
	int i, j;
	char t[15];
	board bd;

	scanf("%d %d", &n, &m);
	init.cnt = 0;
	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		for (j = 1; j <= m; j++) {
			if (t[j] == '#') a[i][j] = -1;
			else if (t[j] == 'O') a[i][j] = 1;
			else if (t[j] == 'R') init.r = make_pair(i, j);
			else if (t[j] == 'B') init.b = make_pair(i, j);
		}
	}


}
