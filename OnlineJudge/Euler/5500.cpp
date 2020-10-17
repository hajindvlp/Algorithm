#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> a, tree;

int sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	else if (left <= start && end <= right) return tree[node];
  int mid = (start+end) >> 1;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx > end || idx < start) return;
	tree[node] += diff;
	if (start != end) {
    int mid = (start+end) >> 1;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
	int i, h, tree_size;
	int x, y, z;

  cin >> n >> m;

	a.resize(n + 1);
	for (i = 1; i <= n; i++) a[i] = 0;

	tree.resize(4*n);
  fill(tree.begin(), tree.end(), 0);

	for (i = 1; i <= m; i++) {
    cin >> x >> y >> z;
		if (x == 1) update(1, 1, n, y, z - a[y]);
		else if (x == 0) cout << sum(1, 1, n, y, z) << "\n";
	}
}