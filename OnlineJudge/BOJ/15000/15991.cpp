#include <stdio.h>
#define MOD 1000000009

long long int d[100005], s[50005];

int main() {
	int i;
	
	s[0] = s[1] = 1;
	s[2] = 2;
	for (i = 3; i <= 50000; i++) s[i] = (s[i - 1] + s[i - 2] + s[i - 3]) % MOD;

	d[1] = 1;
	d[2] = 2;
	for (i = 3; i <= 100000; i++) {
		if (i % 2 == 0) {
			d[i] = (s[i / 2] + s[(i - 2) / 2]) % MOD;
		}
		else {
			d[i] = (s[(i - 1) / 2] + s[(i-3)/2]) % MOD;
		}
	}

	int n;

	scanf("%d", &n);
	while (n--) scanf("%d", &i), printf("%d\n", d[i]);
}