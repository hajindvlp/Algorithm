#include <stdio.h>

int a[10001], d[3][10001], ans, n, mx[10001];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    mx[1] = d[1][1] = d[2][1] = a[1];
    for(i=2 ; i<=n ; i++)
    {
        mx[i] = mx[i-1];
        d[1][i] = a[i]+d[2][i-1];
        d[2][i] = a[i]+mx[i-2];
        if(d[1][i]>mx[i])
            mx[i] = d[1][i];
        if(d[2][i]>mx[i])
            mx[i] = d[2][i];
    }

    printf("%d", mx[n]);
    return 0;
}
