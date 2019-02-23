#include <stdio.h>

int d[201], n, a[201], mx;

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    d[0] = 0;

    for(i=1 ; i<=n ; i++)
        for(j=0 ; j<i ; j++)
            if(a[i]>a[j] && d[i]<d[j]+1)
                d[i] = d[j]+1;

    for(i=1 ; i<=n ; i++)
        if(d[i]>mx)
            mx = d[i];

    printf("%d", n-mx);
    return 0;
}
