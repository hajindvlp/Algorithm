#include <stdio.h>

int n, a[10], sum = 0;

int pw(int x, int y)
{
    int tmp = 1;

    while(y--)
        tmp*=x;
    return tmp;
}

int main()
{
    int i, cnt = 0, t;

    scanf("%d", &n);
    t = n;
    while(n!=0)
    {
        a[++cnt] = n%10;
        n/=10;
    }

    for(i=1 ; i<=cnt ; i++)
        if(a[i]>3)
            sum+=(a[i+1]+1)*pw(10, i-1), printf("%d\n", (a[i+1]+1)*pw(10, i-1));
    printf("%d", t-sum);
}
