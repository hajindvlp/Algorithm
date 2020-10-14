#include <stdio.h>

void pro() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	int t1 = a * 10 + b, t2 = b * 10 + c;
	if (a + b - c == d) printf("%d+%d-%d=%d\n", a, b, c, d);
	else if (a + b * c == d) printf("%d+%d*%d=%d\n", a, b, c, d);
	else if (a * c + b == c * d) printf("%d+%d/%d=%d\n", a, b, c, d);
	else if (a - b + c == d) printf("%d-%d+%d=%d\n", a, b, c, d);
	else if (a - b * c == d) printf("%d-%d*%d=%d\n", a, b, c, d);
	else if (a * c - b == d * c) printf("%d-%d/%d=%d\n", a, b, c, d);
	else if (a * b + c == d) printf("%d*%d+%d=%d\n", a, b, c, d);
	else if (a * b - c == d) printf("%d*%d-%d=%d\n", a, b, c, d);
	else if (a * b == d * c) printf("%d*%d/%d=%d\n", a, b, c, d);
	else if (a + c * b == d * b) printf("%d/%d+%d=%d\n", a, b, c, d);
	else if (a - c * b == d * b) printf("%d/%d-%d=%d\n", a, b, c, d);
	else if (a * c == d * b) printf("%d/%d*%d=%d\n", a, b, c, d);
	else if (t1 + 10 * c == 10 * d) printf("%d.%d+%d=%d\n", a, b, c, d);
	else if (t1 - 10 * c == 10 * d) printf("%d.%d-%d=%d\n", a, b, c, d);
	else if (t1 * c == 10 * d) printf("%d.%d*%d=%d\n", a, b, c, d);
	else if (t1 == d * c) printf("%d.%d/%d=%d\n", a, b, c, d);
	else if (10 * a + t2 == 10 * d) printf("%d+%d.%d=%d\n", a, b, c, d);
	else if (10 * a - t2 == 10 * d) printf("%d-%d.%d=%d\n", a, b, c, d);
	else if (a * t2 == 10 * d) printf("%d*%d.%d=%d\n", a, b, c, d);
	else if (10 * a == d * t2) printf("%d/%d.%d=%d\n", a, b, c, d);
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) pro();
}