#include <stdio.h>

int n, m;
int a[10000001];

int main()
{
    int i, x;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &x), a[x] = 1;

    scanf("%d", &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &x), printf("%d ", a[x]);
}
