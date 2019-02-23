#include<stdio.h>

char a[4][4];

int main()
{
    int n, i, j, l, k;

    a[1][1]=a[1][3]=a[3][1]=a[3][3]='*';
    a[1][2]=a[2][2]=a[2][3]='x';
    scanf("%d", &n);

    for (i=1; i<=3; i++)
        for (l=1; l<=n; l++)
        {
            for (j=1; j<=3; j++)
                for (k=1; k<=n; k++)
                {
                    if(a[i][j] == 0) printf(" ");
                    else printf("%c", a[i][j]);
                }
            printf("\n");
        }
}
