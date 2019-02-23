#include <stdio.h>

int n;
double d[10001], a[10001], mx;

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%lf", &a[i]);
    d[0] = 1;

    for(i=1 ; i<=n ; i++)
        if(a[i]!=0)
            d[i] = d[i-1]*a[i];

    for(i=1 ; i<=n ; i++)
        for(j=0 ; j<i ; j++)
            if(d[i]/d[j]>mx)
                mx = d[i]/d[j];

    printf("%.3lf", mx);
    return 0;
}
