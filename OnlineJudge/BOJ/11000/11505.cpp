#include <stdio.h>
#include <algorithm>
#define MAX_N 1000005
#define MOD 1000000007
using namespace std;

int n, m, k;
int tree[4 * MAX_N], a[MAX_N];

int init(int node, int start, int end) {
	if (start == end) return tree[node] = a[start] % MOD;
	int mid = (start + end) >> 1;
	return tree[node] = (init(node * 2, start, mid) % MOD) * (init(node * 2 + 1, mid + 1, end) % MOD);
}

int query(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 1;
	else if (left <= start && end <= right) return tree[node];
	int mid = (start + end) >> 1;
	return (query(node * 2, start, mid, left, right) % MOD) * (query(node * 2 + 1, mid + 1, end, left, right) % MOD);
}

void update(int node, int start, int end, int pos, int mult, int divs) {
	if (pos < start || end < pos) return;
	else if (start <= pos && pos <= end) tree[node] = (tree[node] / divs) * mult % MOD;
	int mid = (start + end) >> 1;
	update(node * 2, start, mid, pos, mult, divs);
	update(node * 2 + 1, mid + 1, end, pos, mult, divs);
}

int main() {
	int i, j;
	int x, y, z;

	scanf("%d %d %d", &n, &m, &k);
	m += k;

	for (i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			update(1, 1, n, y, z, (a[y] == 0) ? 1 : a[y]);
			a[y] = z;
		}
		else if(x == 2) printf("%d\n", query(1, 1, n, y, z));

	}
}