#include <stdio.h>

int n, a[1001];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n ; i++)
    {
        printf("%d: ", i);
        for(j=1 ; j<=n ; j++)
            if(i!=j)
            {
                if(a[i]>a[j])
                    printf("> ");
                else if(a[i]<a[j])
                    printf("< ");
                else
                    printf("= ");
            }
        printf("\n");
    }
    return 0;
}
