#include <stdio.h>

int n, m, d[1001][1001], a[1001][1001];

int min(int a, int b)
{
    return (a>b)?b:a;
}

int main()
{
    int i, j, mx = 0;
    char tmp[1005];

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=m ; j++)
            a[i][j] = tmp[j]-'0';
    }
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(a[i][j])
            {
                d[i][j] = min(min(d[i-1][j], d[i][j-1]), d[i-1][j-1])+1;
                if(d[i][j]>mx)
                    mx = d[i][j];
            }

    printf("%d", mx*mx);
}
