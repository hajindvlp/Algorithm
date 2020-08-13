#include <stdio.h>
#include <algorithm>
#define min(x, y) ((x)<(y)?(x):(y))
using namespace std;

long long int sum[100005], ans;
int n, d, m;
int a[100005];

int main() {
	int i, j;

	scanf("%d %d %d", &n, &d, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a + 1, a + n + 1);

	for (i = 1; i <= n; i++) sum[i] = sum[i - 1] + (long long int)a[i];
	int lo = 0, hi = n-1;
	ans = (long long int)a[n];


	while (hi > lo) {
		if (a[hi] > m) {
			if (lo + d < hi && (long long int)a[hi] > sum[lo + d] - sum[lo]) ans += (long long int)a[hi], lo += d;
		}
		else ans += a[hi];
		hi--;
	}
	printf("%lld\n", ans);
}