#include <stdio.h>
#include <math.h>

long long int a,x;

int main()
{
    scanf("%lld", &a);
    x = sqrt(a);
    if(pow(x, 2)<a)
        printf("%lld", x+1);
    else
        printf("%lld", x);
    return 0;
}
