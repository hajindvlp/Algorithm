#include <stdio.h>

int n, m, s;
int d[1005], t[1005];

int main() {
	int i, j, x, flag;

	scanf("%d %d %d", &n, &s, &m);
	d[s] = 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &x);
		flag = 0;
		for (j = 0; j <= m; j++)
			if (d[j] == 1) {
				if (j - x >= 0) t[j - x] = 1, flag = 1;
				if (j + x <= m) t[j + x] = 1, flag = 1;
			}
		if (flag == 0) {
			printf("-1");
			return 0;
		}
		for (j = 0; j <= m; j++) d[j] = t[j], t[j] = 0;
	}

	for (i = m; i >= 0; i--) 
		if (d[i]) {
			printf("%d\n", i);
			break;
		}
}