#include <stdio.h>

int n;
int a[103];
long long d[100][21];

int main()
{
    int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	d[0][a[0]] = 1;
	for (i = 1; i < n-1; i++)
    {
		for (j = 0; j <= 20 - a[i]; j++)
			d[i][j] += d[i-1][j + a[i]];
		for (j = a[i]; j <= 20; j++)
			d[i][j] += d[i-1][j - a[i]];
	}
	printf("%lld", d[n - 2][a[n - 1]]);
}
