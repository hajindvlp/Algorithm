#include <stdio.h>

int n;

int main()
{
    int v = 1, i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        v*=i;
    printf("%d", v);
}
