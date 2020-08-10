#include <stdio.h>
#include <string.h>

bool pro() {
	int n;
	char a[7];

	scanf("%s", &a[1]);
	n = strlen(&a[1]);
	if (n == 1 && a[1] == '0') return false;

	for (int i = 1; i <= n / 2; i++) {
		if (a[i] != a[n - i + 1]) {
			printf("no\n");
			return true;
		}
	}
	printf("yes\n");
	return true;
}

int main() {
	while (pro());
}