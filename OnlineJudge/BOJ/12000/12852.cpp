#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int n;
int dist[1000005], path[1000005];
queue<int> Q;
stack<int> ans;

int main() {
	int x, y;

	scanf("%d", &n);
	Q.push(n);
	dist[n] = 1;
	path[n] = -1;
	while (!Q.empty()) {
		y = Q.front(), Q.pop();
		if (y != 1) {
			if (dist[y - 1] == 0 || dist[y - 1] > dist[y] + 1) {
				dist[y - 1] = dist[y] + 1;
				path[y - 1] = y;
				Q.push(y - 1);
			}
			if (y % 2 == 0 && (dist[y / 2] == 0 || dist[y / 2] > dist[y] + 1)) {
				dist[y / 2] = dist[y] + 1;
				path[y / 2] = y;
				Q.push(y / 2);
			}
			if (y % 3 == 0 && (dist[y / 3] == 0 || dist[y / 3] > dist[y] + 1)) {
				dist[y / 3] = dist[y] + 1;
				path[y / 3] = y;
				Q.push(y / 3);
			}
		}
	}

	printf("%d\n", dist[1] - 1);
	x = 1;
	while (x != -1) {
		ans.push(x);
		x = path[x];
	}

	while (!ans.empty()) printf("%d ", ans.top()), ans.pop();
}