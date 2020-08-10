#include <stdio.h>

bool check[10001];

int d(int x)
{
    int tmp;

    tmp = x;
    while(tmp>0)
        x+=tmp%10, tmp/=10;
    return x;
}

int main()
{
    int i, x;
    for(i=1 ; i<=10000 ; i++)
        if(!check[i])
        {
            printf("%d\n", i);
            x = i;
            while(x<=10000)
                check[d(x)] = 1, x = d(x);
        }
    return 0;
}
