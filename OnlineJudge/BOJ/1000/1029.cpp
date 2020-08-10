#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int visit[20], a[20][20];
int n;

int f(int k, int p) {
	int i, mx = 0, t = 0;

	for (i = 1; i <= n; i++) 
		if (!visit[i] && a[k][i] >= p) {
			visit[i] = 1;
			t = f(i, a[k][i]);
			visit[i] = 0;
			mx = max(mx, t);
		}
	13
	return mx + 1;
}

int main() {
	int i, j;
	char t[18];

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		for (j = 1; j <= n; j++) 
			a[i][j] = t[j] - '0';
	}

	visit[1] = 1;
	printf("%d", f(1, 0));
}