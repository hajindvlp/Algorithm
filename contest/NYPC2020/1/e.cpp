#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

int n, k;
int a[10005][1005], pre[1005], v[10005];
set<int> ans;

int main() {
	int i, j, x;

	scanf("%d %d", &n, &k);
	for (j = 1; j <= n; j++) a[0][j] = 1;
	for (i = 1; i <= k; i++) {
		scanf("%d", &x);
		v[i] = x;
		for (j = 1; j <= n; j++) a[i][j] += a[i - 1][j];
		a[i][x]++;
	}
	for (i = 1; i <= k; i++) {
		bool flag = true;
		for (j = 1; j <= n; j++) {
			if (pre[v[i]] == 0) {
				if (j != v[i] && a[i][j] >= 2) flag = false;
			}
			else if(a[i][j] - a[pre[v[i]]][j] >= 2) flag = false;
		}
		if (flag) {
			ans.insert(v[i]);
		}
		pre[v[i]] = i;
	}

	int len = ans.size();
	printf("%d\n", len);

	set<int>::iterator iter;
	for (iter = ans.begin(); iter != ans.end(); ++iter) {
		printf("%d ", *iter);
	}
}