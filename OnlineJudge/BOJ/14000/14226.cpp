#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int> > Q;
int dist[2005][2005], n;

int main() {
	int i, j;

	scanf("%d", &n);

	Q.push({ 1, 0 });
	while (!Q.empty()) {
		pair<int, int> t = Q.front();
		int x = t.first, y = t.second;
		Q.pop();
		if (n == x) {
			printf("%d\n", dist[x][y]);
			break;
		}
		int nx[3] = { x, x + y, x - 1 }, ny[3] = { x, y, y };
		for (i = 0; i < 3; i++) {
			if (nx[i] > 0 && nx[i] <= 2 * n && dist[nx[i]][ny[i]] == 0) {
				Q.push({ nx[i], ny[i] });
				dist[nx[i]][ny[i]] = dist[x][y] + 1;
			}
		}
	}
}