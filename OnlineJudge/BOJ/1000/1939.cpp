#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
#define INF 1000000005
using namespace std;

typedef pair<int, int> pp;
typedef pair<int, pp > ppp;
priority_queue<pp> pQ;

int n, m, s, e;
map<int, map<int, int> > a;
int dist[10005];

int main() {
	int i, j, len;
	int x, y, z;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		if (a[x][y] < z) a[x][y] = a[y][x] = z;
	}
	scanf("%d %d", &s, &e);
	
	pQ.push(make_pair(INF, s));
	while (!pQ.empty()) {
		x = pQ.top().first;
		y = pQ.top().second;
		pQ.pop();

		if (x >= dist[y]) {
			dist[y] = x;
			for (auto it = a[y].begin(); it != a[y].end(); it++) 
				if (dist[it->first] < x) 
					pQ.push(make_pair(min(it->second, x), it->first));
		}
	}

	printf("%d", dist[e]);
}