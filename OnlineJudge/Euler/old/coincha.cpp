#include <stdio.h>

int n;
int d[7490];
int a[6] = {0, 1, 5, 10, 25, 50};

int main()
{
    int i, j;

    scanf("%d", &n);
    d[0] = 1;
    for(i=1 ; i<=5 ; i++)
        for(j=a[i] ; j<=n ; j++)
            d[j] += d[j-a[i]];

    printf("%d", d[n]);
    return 0;
}
