#include <stdio.h>

int n, a[101][101], sum;

int main()
{
    int i, j, k;
    int x, y;

    scanf("%d", &n);
    for(k=1 ; k<=n ; k++)
    {
        scanf("%d %d", &y, &x);
        for(i=y ; i<y+10 ; i++)
            for(j=x ; j<x+10 ; j++)
                a[i][j] = 1;
    }

    for(i=1 ; i<=100 ; i++)
        for(j=1 ; j<=100 ; j++)
            sum+=a[i][j];

    printf("%d", sum);
    return 0;
}
