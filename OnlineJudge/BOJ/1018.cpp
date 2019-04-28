#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int area[51][51];

int go(int r, int c, int color) {
	int ret = 0;
	int i, j;

	for (i=r ; i<r + 8 ; i++) {
		for (j=c; j<c + 8 ; j++) {
			if (j % 2 == 0 && area[i][j] != color) ret++;
			else if (j % 2 == 1 && area[i][j] == color) ret++;
		}
		color = !color;
	}
	return ret;
}

int main(void)
{
	int ret = 9999;
	int i, j;
	char num;

	scanf("%d %d", &n, &m);

	for (i=1 ; i<=n; i++)
		for (j=1 ; j<=m; j++)
		{
			scanf(" %C", &num);
			if (num == 'W') area[i][j] = 0;
			else area[i][j] = 1;
		}

	for (i=1 ; i<=n-7 ; i++)
		for (j=1 ; j<=m-7 ; j++)
		{
			ret = min(ret, go(i, j, 0));
			ret = min(ret, go(i, j, 1));
		}
	printf("%d", ret);
	return 0;
}
