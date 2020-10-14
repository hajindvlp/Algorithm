#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, t, k;
vector<pair<pair<int, bool>, int> > a;

int main() {
	int i, x;

	scanf("%d %d %d", &n, &t, &k);
	for (i = 1; i <= n; i++) scanf("%d", &x), a.push_back({{ abs(x-t), x > t }, i });
	sort(a.begin(), a.end());
	
	for (i = 0; i < k; i++) printf("%d\n", a[i].second);
}