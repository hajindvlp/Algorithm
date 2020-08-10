#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 1000000000
#define MAX_N 100000

using namespace std;

int n, m, a;
vector<int> tree(4*MAX_N);

int update(int node, int start, int end, int pos, int val) {
    if (end < pos || pos < start) return tree[node];
    if (start == end) return tree[node] = val;
	return tree[node] = min(update(node * 2, start, (start + end) / 2, pos, val), update(node * 2 + 1, (start + end) / 2 + 1, end, pos,val));
}

int query(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	int i;
	int x, y;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a), update(1, 1, n, i, a);

	while (m--) {
		scanf("%d %d", &x, &y);
		printf("%d\n", query(1, 1, n, x, y));
	}
} 