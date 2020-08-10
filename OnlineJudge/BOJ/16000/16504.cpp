#include <stdio.h>

long long int n, sum, x;

int main()
{
    int i;

    scanf("%lld", &n);
    for(i=1 ; i<=n*n ; i++)
        scanf("%lld", &x), sum+=x;

    printf("%lld", sum);
    return 0;
}
