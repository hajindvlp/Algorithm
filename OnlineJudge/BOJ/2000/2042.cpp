#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int n, m, k;
vector<long long int> a;
vector<long long int> tree;

long long int init(int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	else return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

long long int sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	else if (left <= start && end <= right) return tree[node];
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx > end || idx < start) return;
	tree[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}

int main() {
	int i, h, tree_size;
	long long int x, y, z;

	scanf("%d %d %d", &n, &m, &k);
	m += k;

	a.resize(n + 1);
	for (i = 1; i <= n; i++) scanf("%lld", &a[i]);

	h = (int)ceil(log2(n));
	tree_size = (1 << (h + 1));
	tree.resize(tree_size + 1);

	init(1, 1, n);

	for (i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		if (x == 1) {
			update(1, 1, n, (int)y, z - a[y]);
			a[y] = z;
		}
		else if (x == 2) printf("%lld\n", sum(1, 1, n, (int)y, (int)z));
	}
}