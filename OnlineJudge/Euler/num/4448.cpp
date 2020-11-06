#include <stdio.h>

int n, a[101];
double  d[101][3], mx[3];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    d[0][1] = 100;
    d[0][2] = 0;
    mx[1] = 100;
    mx[2] = 0;

    for(i=1 ; i<=n ; i++)
    {
        d[i][2] = mx[1]/100*a[i];
        d[i][1] = mx[2]/a[i]*100;
        if(mx[1]<d[i][1])
            mx[1] = d[i][1];
        if(mx[2]<d[i][2])
            mx[2] = d[i][2];
    }

    printf("%.2lf", mx[1]);
    return 0;
}
