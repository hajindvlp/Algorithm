#include <stdio.h>
#include <algorithm>
using namespace std;

char a[18], ans[18];
int n, m;

void out() {
	int i, mo=0, ja=0;

	for (i = 1; i <= m; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' ||
			ans[i] == 'i' || ans[i] == 'o' ||
			ans[i] == 'u') mo++;
		else ja++;
	}
	if (mo < 1 || ja < 2) return;
	else printf("%s\n", ans + 1);
}	

void f(int lev, int s) {	
	int i;

	if (lev == m) {
		out();
		return;
	}

	for (i = s + 1; i <= n - (m - lev) + 1; i++) {
		ans[lev + 1] = a[i];
		f(lev + 1, i);
	}
}

int main() {
	int i;

	scanf("%d %d", &m, &n);
	for (i = 1; i <= n; i++) scanf(" %c", &a[i]);
	sort(a + 1, a + n + 1);
	f(0, 0);
}