#include <stdio.h>

int b[4], d[501][501];

int main()
{
    int i, j, k;
    int x, y;

    for(i=1 ; i<=3 ; i++)
        scanf("%d", &b[i]);

    for(i=0 ; i<=500 ; i++)
        for(j=0 ; j<=500 ; j++)
            d[i][j] = -1;

    d[0][0] = 1;
    for(i=0 ; i<=500 ; i++)
        for(j=0 ; j<=500 ; j++)
            if(d[i][j] == -1)
                for(k=3 ; k>=1 ; k--)
                {
                    if(i-b[k] >= 0 && d[i-b[k]][j]!=-1)
                        d[i][j] = 1-d[i-b[k]][j];
                    else if(j-b[k] >= 0 && d[i][j-b[k]]!=-1)
                        d[i][j] = 1-d[i][j-b[k]];
                }

    for(i=1 ; i<=5 ; i++)
    {
        scanf("%d %d", &x, &y);
        printf("%c\n", 'A'+d[x][y]);
    }

    for(i=1 ; i<=50 ; i++)
    {
        for(j=1 ; j<=50 ; j++)
            printf("%d ", d[i][j]);
        printf("\n");
    }
    return 0;
}