#include <stdio.h>

int n, x, a[101], sum;

int main()
{
    int i;

    scanf("%d %d", &x, &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        sum+=x-a[i];
    }
    printf("%d", sum+x);
    return 0;
}
