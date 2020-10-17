#include <stdio.h>

int n, a[20001], sum;
int av, mn = 100000000;

int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), sum+=a[i];

    av = sum/n;

    sum = 0;
    for(i=1 ; i<=n ; i++)
        sum+=abs(a[i]-av);
    if(mn>sum)
        mn = sum;
    sum = 0;
    for(i=1 ; i<=n ; i++)
        sum+=abs(a[i]-(av+1));
    if(mn>sum)
        mn = sum;
    sum = 0;
    for(i=1 ; i<=n ; i++)
        sum+=abs(a[i]-(av-1));
    if(mn>sum)
        mn = sum;

    printf("%d", mn);
    return 0;
}
