#include <stdio.h>

void pro() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	if (c % a == 0) printf("%d%02d\n", a, c / a );
	else printf("%d%02d\n", c % a, c / a + 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) pro();
}