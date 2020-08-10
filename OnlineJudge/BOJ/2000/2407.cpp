#include <stdio.h>

int factor[105][105];
int comb[105][105];
unsigned long long int ans = 1;

int main() {
	int i, j, t;
	int n, m;

	scanf("%d %d", &n, &m);

	for (i = 2; i <= 100; i++) {
		t = i;
		for (j = 2; j <= 100 && t != 1; j++)
			while (t % j == 0) t /= j, factor[i][j]++;
	}

	for (i = 1; i <= 100; i++) 
		for (j = 1; j <= 100; j++) 
			comb[i][j] += comb[i-1][j] + factor[i][j];

	for (i = 2; i <= 100; i++) {
		for (j = 1; j <= comb[n][i] - comb[m][i] - comb[n - m][i]; j++) {
			ans = (unsigned long long int)ans*i;
		}
	}

	printf("%llu\n", ans);
}