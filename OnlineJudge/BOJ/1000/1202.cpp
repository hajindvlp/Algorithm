#include <stdio.h>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, m;
long long int ans;
priority_queue<pii> g;
multiset<int> b;

int main() {
	int i, j, x, y;

	scanf("%d %d", &n, &m);
	while(n--) scanf("%d %d", &x, &y), g.push({ y, x });
	while(m--) scanf("%d", &x), b.insert(x);

	while(!g.empty()) {
		pii t = g.top();
		g.pop();
		auto it = b.lower_bound(t.second);
		if (it != b.end()) ans += (long long int)t.first, b.erase(it);
	}

	printf("%lld", ans);
}