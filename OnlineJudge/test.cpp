#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("%d", (a>c && b>c)?(c):((a>b&&c>b)?(b):(a)));
}
