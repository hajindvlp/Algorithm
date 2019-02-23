#include <stdio.h>

int fact(int x)
{
    int i, tmp = 1;

    for(i=1 ; i<=x ; i++)
        tmp*=i;
    return tmp;
}

int main()
{
    int i, n, r;

    scanf("%d %d", &n, &r);
    printf("%d", fact(n)/(fact(r)*fact(n-r)));
    return 0;
}
