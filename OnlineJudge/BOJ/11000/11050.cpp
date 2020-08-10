#include <stdio.h>

int fact(int a) {
	int t;

	for (t = 1; a; a--) t *= a;

	return t;
}

int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", fact(a) / (fact(b) * fact(a - b)));
}