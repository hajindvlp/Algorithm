#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1000000000
using namespace std;

int sim[5][5] = { {5, -1, -2, -1, -3}, {-1, 5, -3, -2, -4}, {-2, -3, 5, -2, -2}, {-1, -2, -2, 5, -1}, {-3, -4, -2, -1, INF} };
int map[255], d[105][105], gap[5] = { -3, -4, -2, -1 };
int d1[105], d2[105], l1, l2;
char s1[105], s2[105];

void pro() {
	int i, j;
	int ans;

	scanf("%d %s", &l1, &s1[1]);
	scanf("%d %s", &l2, &s2[1]);

	for (i = 1; i <= l1; i++) d1[i] = map[s1[i]];
	for (i = 1; i <= l2; i++) d2[i] = map[s2[i]];

	for (i = 0; i <= l1; i++) for (j = 0; j <= l2; j++) d[i][j] = -INF;
	d[0][0] = 0;

	for (i = 1; i <= l1; i++) 
		d[i][0] = d[i - 1][0] + gap[d1[i]];
	for (i = 1; i <= l2; i++)
		d[0][i] = d[0][i - 1] + gap[d2[i]];

	for (i = 1; i <= l1; i++) {
		for (j = 1; j <= l2; j++) {
			d[i][j] = max(d[i][j], d[i - 1][j] + gap[d1[i]]);
			d[i][j] = max(d[i][j], d[i][j - 1] + gap[d2[j]]);
			d[i][j] = max(d[i][j], d[i - 1][j - 1] + sim[d1[i]][d2[j]]);
		}
	}

	printf("%d\n", d[l1][l2]);
}

int main() {
	int T;

	map['A'] = 0;
	map['C'] = 1;
	map['G'] = 2;
	map['T'] = 3;

	scanf("%d", &T);
	while (T--) pro();
}