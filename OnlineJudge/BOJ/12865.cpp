#include <stdio.h>

int d[100005], t[100005];
int n, k;

int main() {
	int i, j;
	int x, y, mx = 0;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		t[x] = (t[x] > y) ? t[x] : y;
		for (j = x+1; j <= k; j++) 
			if (d[j-x] > 0 && d[j] < d[j - x] + y) 
				t[j] = d[j - x] + y;
		for (j = 0; j <= k; j++) d[j] = t[j];
	}
		
	for (i = 1; i <= k; i++) 
		mx = (mx > d[i]) ? mx : d[i];
	printf("%d", mx);
}