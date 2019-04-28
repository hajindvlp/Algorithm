#include <stdio.h>

long long int fact(int x)
{
    int i;
    long long int n = 1;

    for(i=1 ; i<=x ; i++)
        n*=i;
    return n;
}

int main()
{
    int a, b, k, kx, ky;

    scanf("%d %d %d", &a, &b, &k);
    kx = k/b;
    ky = k%b;

    printf("%d %d\n", kx, ky);

    printf("%lld", fact(kx+ky-2)/(fact(kx-1)*fact(ky-1))*fact(a-kx+b-ky)/(fact(a-kx)*fact(b-ky)));
}
