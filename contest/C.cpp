#include <stdio.h>
#include <algorithm>
#define INF 1000000000

using namespace std;

int main() {
	int n, m, i, j, ans;
	int a[201], b[201];

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= m; i++) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1);
	ans = 0;
	for (i = n; i >= 1; i--) {
		int mx = INF;
		for (j = 1; j <= m; j++) {
			if ((int)((a[i] & b[j]) | ans) < mx) mx = (int)((a[i] & b[j]) | ans);
		}
		if (i == 1) ans = mx;
		else ans = mx;
	}

	printf("%d", ans);
}