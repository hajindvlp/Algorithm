#include <stdio.h>

int n, a[10001], sum, cnt;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    for(i=1 ; i<=n ; i++)
        if(a[i]<sum/n)
            cnt+=sum/n-a[i];
    printf("%d", cnt);
    return 0;
}
