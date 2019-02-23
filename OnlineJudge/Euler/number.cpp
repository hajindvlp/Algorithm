#include <stdio.h>

int n;
int a[10];

int main()
{
    int i, j;

    scanf("%d", &n);

    if(n == 1)
    {
        printf("1");
        return 0;
    }

    for(i=2 ; i<=9 ; i++)
        while(n%i == 0)
        {
            n/=i;
            a[i]++;
        }
    if(n!=1)
    {
        printf("-1");
        return 0;
    }
    for(i=2 ; i<=9 ; i++)
        for(j=1 ; j<=a[i] ; j++)
            printf("%d", i);
    return 0;
}
