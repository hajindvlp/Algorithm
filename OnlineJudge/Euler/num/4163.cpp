#include <stdio.h>

int a[101][101], d[101], n, m, ;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1  ;j<=m ; j++)
            scanf("%d", &a[i][j]);

    for(i=2 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
            for(k=1 ; k<=m ; k++)
                if(k!=j && a[i][k]>mx)
                    mx = a[i][k]

    }
}
