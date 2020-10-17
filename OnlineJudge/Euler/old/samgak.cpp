#include <stdio.h>

int a[51], n, cnt;

int main()
{
    int i, j, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            for(k=1 ; k<=n ; k++)
                if(a[i]<a[j]+a[k] && a[j]<a[i]+a[k] && a[k]<a[i]+a[j])
                    cnt++;

    printf("%d", cnt);
    return 0;
}
