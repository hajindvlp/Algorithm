#include <stdio.h>

int main()
{
    long long int a, b;

    scanf("%lld %lld", &a, &b);
    if(a>b)
        printf("%lld", a*(a+1)/2-b*(b-1)/2);
    else
        printf("%lld", b*(b+1)/2-a*(a-1)/2);
}
