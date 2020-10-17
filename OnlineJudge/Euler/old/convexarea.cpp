#include <stdio.h>

int x[101], y[101], n;
double ans;

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

int main()
{
    int i;
    int asum = 0, bsum = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &x[i], &y[i]);

    for(i=1 ; i<=n-1 ; i++)
        asum+=x[i]*y[i+1], bsum+=y[i]*x[i+1];
    asum+=x[n]*y[1], bsum+=y[n]*x[1];

    printf("%.1lf", (double)abs(asum-bsum)/2);
    return 0;
}
