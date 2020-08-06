#include <stdio.h>

int a[15];

int main() {
	long long int n;

	scanf("%lld", &n);
	printf("%lld", (n-1)*(n)/2);
}