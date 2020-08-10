#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;

int main() {
	int i, n;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) Q.push(i);

	while (Q.size() > 1) {
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}

	printf("%d", Q.front());
}