#include <stdio.h>

int main() {
	unsigned long long int a, b, c, t;

	scanf("%llu %llu %llu", &a, &b, &c);
	t = 1;

	while (b--) t = (t * a) % c;

	printf("%llu", t);
}