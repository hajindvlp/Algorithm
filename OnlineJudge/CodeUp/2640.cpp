#include <stdio.h>

int main()
{
    int n, k, i;
    long long int x =1;

    scanf("%d %d", &n, &k);

    for(i=1 ; i<=k ; i++)
        x = (x*n)%1000000007;
    printf("%lld", x);
}
