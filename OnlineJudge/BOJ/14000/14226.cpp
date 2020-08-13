#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int> > piii;

int n;
int d[1005];
priority_queue<piii, vector<piii>, greater<piii> > Q;

int main() {
	scanf("%d", &n);
	Q.push({ 0, {1, 0} });
	while (!Q.empty()) {

	}
}