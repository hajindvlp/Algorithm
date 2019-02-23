#include <stdio.h>

long long int a, b, c, n, m, l;
long long int mx;

long long int gcd(long long int x, long long int y)
{
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int main()
{
    long long int i;

    scanf("%lld %lld %lld %lld %lld %lld", &a, &n, &b, &m, &c, &l);

    mx = (a*b)/gcd(a, b);
    mx = (c*mx)/gcd(c, mx);

    for(i=1 ; i<=mx ; i++)
        if(i%a == n && i%b == m && i%c == l)
        {
            printf("%lld", i);
            return 0;
        }
    printf("-1");
    return 0;
}
