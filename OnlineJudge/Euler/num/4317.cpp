#include <stdio.h>

int n, a[46];

int main()
{
    int i;

    scanf("%d", &n);
    a[1] = 2;
    a[2] = 3;
    for(i=3 ; i<=n ; i++)
        a[i] = a[i-1]+a[i-2];

    printf("%d", a[n]);
    return 0;
}
