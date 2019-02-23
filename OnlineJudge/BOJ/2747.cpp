#include <stdio.h>

const int mod = 1000000;
const int p = mod/10*15;
int fibo[p] = {0, 1};

int main()
{
    long long n, i;

    scanf("%lld", &n);
    for(i=2 ; i<p ; i++)
        fibo[i] = (fibo[i-1]+fibo[i-2])%mod;

    printf("%d", fibo[n%p]);
    return 0;
}
