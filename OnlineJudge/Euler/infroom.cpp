#include <stdio.h>

long long n, i;

int main()
{
    scanf("%lld %lld", &i, &n);
    while(n>0)
    {
        n-=i;
        i++;
    }
    printf("%lld", i-1);
}
