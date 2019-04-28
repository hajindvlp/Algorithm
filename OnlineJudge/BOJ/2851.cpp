#include <stdio.h>

int sum, mn = 1000000000, ans, a;

int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

int main()
{
    int i;

    for(i=1 ; i<=10 ; i++)
    {
        scanf("%d", &a), sum+=a;
        if(abs(100-sum)<=mn)
            mn = abs(100-sum), ans = sum;
    }
    printf("%d", ans);
}
