#include <stdio.h>

int n, cnt;

int sq(int x)
{
    return x*x;
}

int main()
{
    int i, j;

    scanf("%d", &n);

    for(i=1 ; i<=500 ; i++)
        for(j=1 ; j<=i-1 ; j++)
            if(sq(i) == sq(j)+n)
                cnt++;
    printf("%d", cnt);
    return 0;
}
