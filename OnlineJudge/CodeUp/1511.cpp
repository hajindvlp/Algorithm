#include <stdio.h>

int main()
{
    int n, i ,j ,sum = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(i == 1 || i==n || j==1 || j==n)
                sum+=(i-1)*n+j;

    printf("%d", sum);
    return 0;
}
