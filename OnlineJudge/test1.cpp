#include <stdio.h>

int gcd(int a, int b)
 {
    if (a == 0 || b == 0)
        return 0;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int lcm(int a, int  b)
{
    return (a*b)/gcd(a, b);
}

int main()
{
    int n, i;
    int tmp = 1;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        tmp = lcm(tmp, i);

    printf("%d", tmp);

}
