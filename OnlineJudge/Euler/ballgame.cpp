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
            for(k=1 ; k<=3 ; k++)
            {
                if(i-b[k]>=0 && d[i-b[k]][j] == 0) d[i][j] = 1;
                if(j-b[k]>=0 && d[i][j-b[k]] == 0) d[i][j] = 1;
            }

    for(i=1 ; i<=5 ; i++)
    {
        scanf("%d %d", &x, &y);
        printf("%c\n", (d[x][y]==1)?'A':'B');
    }

    return 0;
}
