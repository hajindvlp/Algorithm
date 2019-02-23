#include <stdio.h>

int n;

int main()
{
    int i, j;

    scanf("%d", &n);
    int tmp = n*(n+1)/2;

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=i ; j++)
            printf("%d ", tmp--);
        printf("\n");
    }

    return 0;
}
