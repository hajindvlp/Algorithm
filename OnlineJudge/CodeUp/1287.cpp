#include <stdio.h>

int main()
{
    int i, j, n;

    scanf("%d", &n);
    for(i=1 ; i<=9 ; i++)
    {
        for(j=1 ; j<=n*i ; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
