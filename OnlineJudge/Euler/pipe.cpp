#include <stdio.h>

int n, m;
int a[51], b[1024], cnt[51][1024];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &b[i]);
}
