#include <stdio.h>

int n;
int d[1000001];

int rec(int x)
{
    int cnt = 1;
    int tmp = x;

    while(x != 1)
    {
        cnt++;
        if(x<=1000000 && d[x] != 0)
        {
            d[tmp] = cnt+d[x];
            break;
        }
        else
        {
            if(x%2 == 0)
                x/=2;
            else
                x = x*3+1;
        }
    }
    if(x == 1)
        d[tmp] = cnt;

    return d[tmp];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i;

    for(i=1 ; i<=1000000 ; i++)
        rec(i), printf("%d\n", i);
    printf("done");
    return 0;
}
