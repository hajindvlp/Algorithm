#include <stdio.h>
#define min(x, y) ((x) > (y)?(y):(x)) 

void pro() {
	int r, g, b, w, mn;

	scanf("%d %d %d %d", &r, &g, &b, &w);
	mn = r;
	mn = min(mn, g);
	mn = min(mn, b);

	int mMod = (r + g + b + w) % 2;
	if (mn == 0) {
		int sum = r % 2 + g % 2 + b % 2 + w % 2;
		if (mMod == 0 && sum >= 2) printf("NO\n");
		else if (mMod == 1 && sum != 1) printf("NO\n");
		else printf("YES\n");
	}
	else {
		int sum = r % 2 + g % 2 + b % 2 + w % 2;
		if (sum == 2) printf("NO\n");
		else printf("YES\n");
	}
}

int main() {
	int T;

	scanf("%d", &T);
	while (T--) pro();
}