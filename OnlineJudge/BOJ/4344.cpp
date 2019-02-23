#include <stdio.h>

void pro()
{
    int n, sum, i;
    double av, a[1001], cnt;

    sum = 0;
    av = 0;
    cnt = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%lf", &a[i]), sum+=a[i];

    av = (double)sum/(double)n;

    for(i=1 ; i<=n ; i++)
        if(av<a[i])
            cnt++;

    printf("%.3lf%%\n", cnt/n*100);
}

int main()
{
    int n;

    scanf("%d", &n);
    while(n--)
        pro();
    return 0;
}
