#include <stdio.h>

int n, d[100001] = {1, 3};

int main()
{
    int i;

    scanf("%d", &n);
    for(i=2 ; i<=n ; i++)
        d[i] = (d[i-1]*2+d[i-2])%9901;
    printf("%d", d[n]);
}
