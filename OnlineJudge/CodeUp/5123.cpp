#include <stdio.h>

int n, a[8001], cnt;

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=i ; j++)
            if(i!=j && (a[i]+a[j])%3 == 0)
                cnt++;

    printf("%d", cnt);
    return 0;
}
