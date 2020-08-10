#include <stdio.h>

int n;

int main()
{
    int i, x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d,%d", &x, &y), printf("%d\n", x+y);
}
