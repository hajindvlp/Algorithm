#include <stdio.h>

int n, m, a[101][101], l[100001], sum;

int main()
{
    int i, j, k;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &l[i]);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    for(k=1 ; k<=n ; k++)
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=n ; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j] = a[i][k]+a[k][j];

    for(i=2 ; i<=m ; i++)
        sum+=a[l[i-1]][l[i]];

    printf("%d", sum);
    return 0;
}
