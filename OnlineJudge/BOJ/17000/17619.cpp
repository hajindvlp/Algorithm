#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<pair<pair<int, int>, int> > a;

int main() {
	int x1, x2, y;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x1, &x2, &y);
		a.push_back({ { x1, x2 }, y });
	}

	sort(a.begin(), a.end());


}