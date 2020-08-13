#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

queue<int> Q;
vector<int> d;
int F, S, G, U, D;

int main() {
	int i, j;

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	d.resize(F + 1, INF);
	d[S] = 0;
	Q.push(S);
	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		if (t + U <= F && d[t + U] > d[t] + 1) {
			d[t + U] = d[t] + 1;
			Q.push(t + U);
		} 
		if (t - D >= 1 && d[t - D] > d[t] + 1) {
			d[t - D] = d[t] + 1;
			Q.push(t - D);
		}
	}

	if (d[G] >= INF) printf("use the stairs\n");
	else printf("%d\n", d[G]);
}