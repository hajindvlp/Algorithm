#include <stdio.h>

int n, a[400001], p, cnt;

int pow(int x, int y)
{
    int tmp = x;

    y--;
    while(y--)
        x*=tmp;

    return x;
}

int main()
{
    int tmp = 0, sum = 0;

    scanf("%d %d", &n, &p);
    while(1)
    {
        if(a[n]!=0)
        {
            printf("%d", a[n]-1);
            return 0;
        }
        else
        {
            a[n] = ++cnt;
            sum = 0;
            while(n != 0)
            {
                tmp = n%10;
                n /= 10;
                sum+=pow(tmp, p);
            }
            n = sum;
        }
    }
    return 0;
}
