#include <stdio.h>
#include <algorithm>
#define MAX_N 1000005
#define MOD 1000000007

typedef long long int ll;
using namespace std;

ll n, m, k, x, y, z, i;
ll tree[MAX_N * 4];

ll update(ll pos, ll val, ll node, ll x, ll y) {
	if (pos < x || y < pos) return tree[node];
	if (x == y) return tree[node] = val;
	ll mid = (x + y) >> 1;
	return tree[node] = (update(pos, val, node * 2, x, mid) * update(pos, val, node * 2 + 1, mid + 1, y)) % MOD;
}

ll query(ll lo, ll hi, ll node, ll x, ll y) {
	if (hi < x || y < lo) return 1;
	if (lo <= x && y <= hi) return tree[node];
	ll mid = (x + y) >> 1;
	return (query(lo, hi, node * 2, x, mid) * query(lo, hi, node * 2 + 1, mid + 1, y)) % MOD;
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	m += k;

	for (i = 1; i <= n; i++) scanf("%lld", &x), update(i, x, 1, 1, n);

	for (i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		if (x == 1) update(y, z, 1, 1, n);
		else printf("%lld\n", query(y, z, 1, 1, n));
	}
}