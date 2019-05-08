#include <stdio.h>

int main()
{
    int a, b;
    int i, j;


    scanf("%d %d", &a, &b);

    for(i=1 ; i<=(a>0)?(a/2):(-a/2+1) ; i++)
    {
        for(j=1 ; j<=(a>0)?(i-1):(-a/2-i+1) ; j++)
            printf(" ");
        for(j=1 ; j<=b ; j++)
            printf("*");
        printf("\n");
    }
    for(i=1 ; i<=(a>0)?(a/2+1):(-a/2) ; i++)
    {
        for(j=1 ; j<=(a>0)?(a/2-i+1):(i) ; j++)
            printf(" ");
        for(j=1 ; j<=b;  j++)
            printf("*");
        printf("\n");
    }
}
