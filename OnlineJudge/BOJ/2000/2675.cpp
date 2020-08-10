#include <stdio.h>
#include <string.h>

void pro() {
	char a[23];
	int i, j, n;

	for (i = 1; i <= 22; i++) a[i] = 0;
	scanf("%d %s", &n, &a[1]);

	for (i = 1; i <= strlen(&a[1]); i++) {
		for (j = 1; j <= n; j++) printf("%c", a[i]);
	}
	printf("\n");
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) pro();
}