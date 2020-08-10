#include <stdio.h>

int main() {
	int n, a, b, t;

	a = 1;
	b = 0;
	scanf("%d", &n);
	while (n--) {
		t = a;
		a = (a + b) % 10;
		b = t;
	}

	printf("%d", a % 10);
}