#include <stdio.h>

int n, m, x, y, cnt;

int main()
{
    int i, j, k, l;

    scanf("%d %d %d %d", &n, &m, &x, &y);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=x ; j++)
        {
            for(k=1 ; k<=m ; k++)
                for(l=1 ; l<=y ; l++)
                {
                    if(i%2 == 1)
                    {
                        if(k%2 == 1)
                            printf("X");
                        else
                            printf(".");
                    }
                    else
                    {
                        if(k%2 == 1)
                            printf(".");
                        else
                            printf("X");
                    }
                }
            printf("\n");
        }
    return 0;
}
