#include <stdio.h>

int d[405][405], a[405][405], n, suma[405][405], sumb[405][405];
int mn = -100000000;

int main()
{
    int i, j, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]), d[i][j] = -10000000;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
        {
            suma[i][j] = a[i][j]+suma[i-1][j-1];
            sumb[i][j] = a[i][j]+sumb[i-1][j+1];
        }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            for(k=2 ; k<=n ; k++)
                if(i>=k && j>=k && suma[i][j]-suma[i-k][j-k]-(sumb[i][j-k+1]-sumb[i-k][j+1])>d[i][j])
                    d[i][j] = suma[i][j]-suma[i-k][j-k]-(sumb[i][j-k+1]-sumb[i-k][j+1]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(mn<d[i][j])
                mn = d[i][j];

    printf("%d", mn);
    return 0;
}
