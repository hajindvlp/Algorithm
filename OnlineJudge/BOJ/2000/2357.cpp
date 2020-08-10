#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 1000000000
#define MAX_N 100000

using namespace std;

int n, m, a;
vector<int> maxSeg(4 * MAX_N), minSeg(4 * MAX_N);

int minUpdate(int node, int start, int end, int pos, int val) {
	if (end < pos || pos < start) return minSeg[node];
	if (start == end) return minSeg[node] = val;
	return minSeg[node] = min(minUpdate(node * 2, start, (start + end) / 2, pos, val), minUpdate(node * 2 + 1, (start + end) / 2 + 1, end, pos, val));
}

int minQuery(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return INF;
	if (left <= start && end <= right) return minSeg[node];
	int mid = (start + end) >> 1;
	return min(minQuery(node * 2, start, mid, left, right), minQuery(node * 2 + 1, mid + 1, end, left, right));
}

int maxUpdate(int node, int start, int end, int pos, int val) {
	if (end < pos || pos < start) return maxSeg[node];
	if (start == end) return maxSeg[node] = val;
	return maxSeg[node] = max(maxUpdate(node * 2, start, (start + end) / 2, pos, val), maxUpdate(node * 2 + 1, (start + end) / 2 + 1, end, pos, val));
}

int maxQuery(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return -INF;
	if (left <= start && end <= right) return maxSeg[node];
	int mid = (start + end) >> 1;
	return max(maxQuery(node * 2, start, mid, left, right), maxQuery(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	int i;
	int x, y;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a), maxUpdate(1, 1, n, i, a), minUpdate(1, 1, n, i, a);

	while (m--) {
		scanf("%d %d", &x, &y);
		printf("%d %d\n", minQuery(1, 1, n, x, y), maxQuery(1, 1, n, x, y));
	}
}