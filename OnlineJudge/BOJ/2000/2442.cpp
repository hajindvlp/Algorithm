#include <stdio.h>

int n;

int main()
{
    int i, j;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n-i ; j++)
            printf(" ");
        for(j=1 ; j<=i*2-1 ; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
