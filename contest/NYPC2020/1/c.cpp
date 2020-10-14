#include <stdio.h>

void pro() {
	int i;
	int x, asum, bsum, amx, bmx;
	asum = bsum = amx = bmx = 0;
	
	for (i = 1; i <= 4; i++) scanf("%d", &x), asum += x, amx = (amx > x) ? amx : x;
	for (i = 1; i <= 4; i++) scanf("%d", &x), bsum += x, bmx = (bmx > x) ? bmx : x;

	if (asum > bsum && amx <= bmx) printf("S\n");
	else if (amx > bmx && asum <= bsum) printf("I\n");
	else printf("R\n");
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) pro();
}