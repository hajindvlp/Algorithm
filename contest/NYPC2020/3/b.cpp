#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int N, cnt;
vector<pii> a, ans;
map<pii, int> ca, up, down, left, right, mn;

int main() {
	int i, j;
	int x, y, p;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		a.push_back({ x, y });
		ca[a[i]] = 1;
	}

	sort(a.begin(), a.end());
	for (i = 0; i < N; i++) left[a[i]] = left[{a[i].first, a[i].second - 1}] + 1;
	for (i = 0; i < N; i++) up[a[i]] = up[{a[i].first - 1, a[i].second}] + 1;
	for (i = N - 1; i > 0; i--) right[a[i]] = right[{a[i].first, a[i].second + 1}] + 1;
	for (i = N - 1; i > 0; i--) down[a[i]] = down[{a[i].first + 1, a[i].second}] + 1;

	for (i = 0; i < N; i++) {
		mn[a[i]] = min(min(left[a[i]], right[a[i]]), min(up[a[i]], down[a[i]]));
		y = a[i].first, x = a[i].second, p = mn[a[i]];
		if (p > 1) {
			p--;
			cnt++;
			ans.push_back(a[i]);
			for (j = y - p; j <= y + p; j++) ca[{j, x}] = 0;
			for (j = x - p; j <= x + p; j++) ca[{y, j}] = 0;
		}
	}

	for (i = 0; i < N; i++) if (ca[a[i]]) {
		printf("-1");
		return 0;
	}
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++) printf("%d %d %d\n", ans[i].first, ans[i].second, mn[ans[i]]-1);
}