#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, mx, sum;
int a[52][52];

int main() {
	int i, j, k;
	char t[55];

	memset(a, 0x3f, sizeof(a));

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", &t[1]);
		for (j = 1; j <= n; j++) 
			if (t[j] == 'Y')
				a[i][j] = 1;
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j];

	for (i = 1; i <= n; i++) {
		sum = 0;
		for (j = 1; j <= n; j++) {
			if (i == j) continue;
			sum += (a[i][j] < 3) ? 1 : 0;
		}
		if (sum > mx) mx = sum;
	}

	printf("%d", mx);
	return 0;
}