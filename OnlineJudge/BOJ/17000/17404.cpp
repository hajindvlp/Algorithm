#include <stdio.h>
#define INF 1000000000

int n;
int a[1005][4];
int s[5][5];

int main() {
	int i, j, k, l, mn;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
	for (i = 1; i <= 3; i++) s[i][1] = s[i][2] = a[1][i];
	for (k = 2; k <= n; k++) {
		if (k % 2) {
			s[1][1] += a[k][2];
			s[1][2] += a[k][3];
			s[2][1] += a[k][1];
			s[2][2] += a[k][3];
			s[3][1] += a[k][1];
			s[3][2] += a[k][2];
		}
		else {
			s[1][1] += a[k][3];
			s[1][2] += a[k][2];
			s[2][1] += a[k][3];
			s[2][2] += a[k][1];
			s[3][1] += a[k][2];
			s[3][2] += a[k][1];
		}
	}

	mn = INF;
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 2; j++) 
			if (mn > s[i][j]) mn = s[i][j];
	}
	printf("%d\n", mn);
}