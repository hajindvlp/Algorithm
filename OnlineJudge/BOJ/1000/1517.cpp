#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long int cnt;
vector<pair<int, int> > a;

int main() {
	int i, x;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &x), a.push_back({ x, i });
	sort(a.begin(), a.end());
	for (i = 0; i < n; i++) cnt += (long long int)(a[i].first - i);
}