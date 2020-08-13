#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

typedef pair<int, int> pii;

vector<vector<pii> > in, out;
vector<int> din, dout;
priority_queue<pii, vector<pii>, greater<pii> > Q;
int n, m, s, mx;

int main() {
	int i, j, x, y, z;

	scanf("%d %d %d", &n, &m, &s);
	in.resize(n + 1), out.resize(n + 1), din.resize(n + 1, INF), dout.resize(n + 1, INF);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		in[x].push_back({ y, z });
		out[y].push_back({ x, z });
	}

	Q.push({ 0, s });
	din[s] = 0;
	while (!Q.empty()) {
		pii t = Q.top();
		Q.pop();
		int len = in[t.second].size();
		for (i = 0; i < len; i++) 
			if (din[in[t.second][i].first] > din[t.second] + in[t.second][i].second) {
				din[in[t.second][i].first] = din[t.second] + in[t.second][i].second;
				Q.push({ din[in[t.second][i].first], in[t.second][i].first });
			}
	}
	Q.push({ 0, s });
	dout[s] = 0;
	while (!Q.empty()) {
		pii t = Q.top();
		Q.pop();
		int len = out[t.second].size();
		for (i = 0; i < len; i++) 
			if (dout[out[t.second][i].first] > dout[t.second] + out[t.second][i].second) {
				dout[out[t.second][i].first] = dout[t.second] + out[t.second][i].second;
				Q.push({ dout[out[t.second][i].first], out[t.second][i].first });
			}
	}

	for (i = 1; i <= n; i++) {
		mx = max(mx, din[i] + dout[i]);
	}
	printf("%d\n", mx);
}