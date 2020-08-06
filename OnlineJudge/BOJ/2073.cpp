#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;

int D, P;
int d[100005], t[100005];

int main() {
	int i, j;
	int x, y;

	scanf("%d %d", &D, &P);
	d[0] = INF;
	for (i = 1; i <= P; i++) {
		scanf("%d %d", &x, &y);
		for (j = x; j <= D; j++) 
			if (d[j - x] > 0 && d[j] < min(d[j - x], y)) 
				t[j] = min(d[j - x], y);
		for (j = 1; j <= D; j++) d[j] = t[j];
	}

	printf("%d\n", d[D]);
}