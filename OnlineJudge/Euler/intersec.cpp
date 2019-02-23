#include <stdio.h>

int n;

int main()
{
    scanf("%d", &n);
    printf("%d", (n*(n-1)*(n-2)*(n-3))/(4*3*2*1));
    return 0;
}
