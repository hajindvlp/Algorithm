#include <stdio.h>

int n;
long long int a[101];

int main()
{
    int i;

    scanf("%d", &n);
    a[0] = a[1] = a[2] = a[3] = 1;
    a[4] = a[5] = 2;
    for(i=6 ; i<=n ; i++)
        a[i] = a[i-1]+a[i-5];

    printf("%lld", a[n]);
    return 0;
}
