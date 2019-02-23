#include <stdio.h>

int a[6], n = 5, tmp;

bool isOk()
{
    int i;

    for(i=1 ; i<=n ; i++)
        if(a[i]!=i)
            break;
    if(i == n+1)
        return true;
    return false;
}

int main()
{
    int i, j;

    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    while(!isOk())
    {
        for(i=1 ; i<=n-1 ; i++)
            if(a[i]>a[i+1])
            {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                for(j=1 ; j<=n ; j++)
                    printf("%d ", a[j]);
                printf("\n");
            }
    }
    return 0;
}
