#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

char b[1005], nxt[256], cnt[256];
int d[1005], visit[1005];
int mn, v, sum;

int main() {
	int n, i, j;
	char s[1005];
	
	scanf("%s", &s[1]);
	n = strlen(&s[1]);

	for (i = 1; i <= n; i++) b[i] = s[i], cnt[s[i]]++;
	sort(b + 1, b + n + 1);

	v = b[0];
	for (i = 0; i < n; i++) 
		if (v != b[i]) {
			nxt[v] = b[i];
			v = b[i];
		}

	for (i = 2; i <= n; i++) d[i] = INF;

	for (i = 1; i <= n; i++) {
		mn = INF;
		for(j=1 ; j<=n ; j++) 
			if (!visit[j] && mn > d[j]) {
				mn = d[j];
				v = j;
			}
		for (j = 1; j <= n; j++) {
			if (d[j] >= INF) printf(". ");
			else printf("%d ", d[j]);
		}
		printf("%c %d\n", s[v], mn);
		cnt[s[v]]--;
		sum += mn;
		visit[v] = 1;
		for (j = 1; j <= n; j++)
			if (((cnt[s[v]] == 0 && s[j] == nxt[s[v]]) ||
				 (cnt[s[v]] != 0 && s[j] == s[v])) && 
				d[j] > abs(j - v))
				d[j] = abs(j - v);
	}
	printf("%d", sum + n);
}