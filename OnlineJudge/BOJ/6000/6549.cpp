#include <stdio.h>
#include <algorithm>
#define MAX_N 100005
#define INF 1000000000
using namespace std;

long long int tree[4 * MAX_N];
int n;

int update(int node, int start, int end, int pos, long long int val) {
	if (pos < start || pos > end) return tree[node];
	else if (start == end) return tree[node] = val;
	int mid = (start + end) >> 1;
	return tree[node] = min(update(node * 2, start, mid, pos, val), update(node * 2 + 1, mid + 1, end, pos, val));
}

int query(int node, int start, int end, int left, int right) {
	if (right < start || end < right) return 0;
	else if (start <= left && right <= end) return tree[node];
	int mid = (start + end) >> 1;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

long long int solve(int left, int right) {
	int m = query(1, 1, n, left, right);
	printf("%d ", (right - left + 1) * m);
	return 0;
}

bool pro() {
	int i, j;
	long long int a;

	scanf("%d", &n);
	if (n == 0) return false;
	tree[0] = INF;
	for (i = 1; i <= n; i++) scanf("%lld", &a), update(1, 1, n, i, a);
	printf("%lld\n", solve(1, n));
	return true;
}

int main() {
	while (pro());
}