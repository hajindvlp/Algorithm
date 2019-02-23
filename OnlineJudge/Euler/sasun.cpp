#include <stdio.h>

double ans = 0;

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

double sasun(int x1,int x2,int x3,int y1,int y2,int y3)
{
    double tmp;

    tmp = (double)((double)abs((x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3))/2);
    return tmp;
}

int main()
{
    int n, i;
    int x1, x2, x3, y1, y2, y3;

    scanf("%d", &n);
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    for(i=1 ; i<=n-2 ; i++)
    {
        scanf("%d %d", &x3, &y3);
        ans+=sasun(x1, x2, x3, y1, y2, y3);
        x2 = x3;
        y2 = y3;
    }
    printf("%.1lf", ans);
    return 0;
}
