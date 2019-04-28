#include <stdio.h>

int n, a;
int g = 1;

int gcd(int a, int b)
{
    if(b == 0)
        return  a;
    else
        return gcd(b, a%b);
}

int main()
{
    int i;

    scanf("%d", &n);
    for(i=2 ; i<=n ; i++)
        a = i, g = (g*a)/gcd(g, a);
    printf("%d", g);
    return 0;

}
