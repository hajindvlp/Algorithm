#include <stdio.h>

int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

int main()
{
    int n, sum = 0;

    scanf("%d", &n);
    while(n)
    {
        if(n<0)
            sum-=abs(n%10), n/=10;
        else
            sum+=n%10, n/=10;
    }
    printf("%d", sum);
    return 0;
}
