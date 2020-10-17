#include <stdio.h>

int n, a[150001], d[150001][3], mx1, mx2;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    d[1][1] = mx1 = a[1];
    d[1][1] = mx2 = 0;

    for(i=2 ; i<=n ; i++)
    {
        d[i][1] = mx2+a[i];
        d[i][2] = mx1-a[i];
        if(d[i][1]>mx1)
            mx1 = d[i][1];
        if(d[i][2]>mx2)
            mx2 = d[i][2];
    }

    if(mx1>mx2)
        printf("%d", mx1);
    else
        printf("%d", mx2);
    return 0;
}
