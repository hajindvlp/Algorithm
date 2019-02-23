#include <stdio.h>

int n, a[21][21];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i][1]);

    for(i=1 ; i<=n ; i++)
        for(j=2 ; j<=i ; j++)
            a[i][j] = a[i][j-1]-a[i-1][j-1];

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=i ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
