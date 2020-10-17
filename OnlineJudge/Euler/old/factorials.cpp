#include <stdio.h>

int n, a = 1;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        a*=i;
        while(a%10==0)
            a/=10;
        a%=100000;
    }
    printf("%d", a%10);
}
