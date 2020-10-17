#include <stdio.h>
#include <string.h>

int n, m, a[21];
int d[10001];

int main()
{
    int i, j;
    int t;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        for(i=1 ; i<=n ; i++)
            scanf("%d", &a[i]);
        scanf("%d", &m);

        d[0] = 1;
        for(i=1 ; i<=n ; i++)
            for(j=a[i] ; j<=m ; j++)
                d[j]+=d[j-a[i]];

        printf("%d\n", d[m]);
        memset(d,0,sizeof(d));
    }
    return 0;
}
