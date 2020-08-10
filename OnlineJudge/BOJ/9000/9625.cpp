#include <stdio.h>

int main() {
	int n, a = 1, b = 0, t;

	scanf("%d", &n);

	while (n--) {
		t = a;
		a = b;
		b = t + b;
	}
	printf("%d %d\n", a, b);
}