#include <stdio.h>

int n, m, a[100001], mx = -1000000000;

int main()
{
    int i, x;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &x);
        a[i] = a[i-1]+x;
    }

    for(i=m ; i<=n ; i++)
        if(a[i]-a[i-m]>mx)
            mx = a[i]-a[i-m];

    printf("%d", mx);
    return 0;
}
