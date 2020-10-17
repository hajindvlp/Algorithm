#include <stdio.h>

void pro()
{
    long long int n;
    long long int t;

    scanf("%lld", &n);
    t = n*(n-3)/2;

    if(n>=3)
        printf("%lld", (t*t + t + 2)/2 + n);
    else 
        printf("%lld", n);
}

int main()
{
    int n;

    scanf("%d", &n);
    while(n--)
        pro();

    return 0;
}