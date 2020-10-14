#include <stdio.h>
#define MAX_N 100000

typedef long long int ll;

ll n, m, x, y, a, b, i;
ll seg[MAX_N * 4];

ll update(ll pos, ll val, ll node, ll x, ll y) {
	if (y < pos || x > pos) return seg[node];
	if (y == x) return seg[node] = val;
	ll mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(ll lo, ll hi, ll node, ll x, ll y) {
	if (y < lo || x > hi) return 0;
	if (lo <= x && y <= hi) return seg[node];
	ll mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	scanf("%lld%lld", &n, &m);
	for (i = 1; i <= n; i++) scanf("%lld", &x), update(i, x, 1, 1, n);
	for (i = 1; i <= m; i++) {
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		printf("%lld\n", (y>x)?query(x, y, 1, 1, n):query(y, x, 1, 1, n));
		update(a, b, 1, 1, n);
	}
}