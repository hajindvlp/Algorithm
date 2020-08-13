#include <stdio.h>
#define abs(x) ((x)>0 ? (x) : -(x) )

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    a = abs(a);
    b = abs(b);
    if (a + b > c || (c - a - b) % 2 != 0) printf("NO");
    else if ((c - a - b) % 2 == 0) printf("YES");
}