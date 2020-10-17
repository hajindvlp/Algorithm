#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<vector<int> > a;
vector<int> p;
queue<int> Q;

int main() {
	int x, y;
	int i, j;


	scanf("%d", &n);
	a.resize(n + 1);
	p.resize(n + 1);
	for (i = 1; i <= n - 1; i++) {
		scanf("%d %d", &x, &y);
		a[x].push_back(y), a[y].push_back(x);
	}

	Q.push(1);
	while (!Q.empty()) {
		y = Q.front();
		Q.pop();
		int len = a[y].size();
		for (i = 0; i < len; i++) 
			if (p[a[y][i]] == 0) {
				p[a[y][i]] = y;
				Q.push(a[y][i]);
			}
	}

	for (i = 2; i <= n; i++) printf("%d\n", p[i]);		
}