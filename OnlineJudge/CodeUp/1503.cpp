#include <stdio.h>

int main()
{
    int i, j, n;
    int a[101][101];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        if(i%2 == 0)
            for(j=1 ; j<=n ; j++)
                a[i][j] = (i-1)*n+(n-j+1);
        else
            for(j=1 ; j<=n ; j++)
                a[i][j] = (i-1)*n+j;
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
    return 0;
}
