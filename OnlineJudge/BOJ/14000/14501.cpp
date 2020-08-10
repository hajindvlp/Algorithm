#include <stdio.h>

int d[26], mx[26], a[16][3];
int n, mn;

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d" , &a[i][1], &a[i][2]);

    for(i=1 ; i<=n ; i++)
        if(d[i+a[i][1]-1] < mx[i]+a[i][2])
        {
            d[i+a[i][1]-1] = mx[i]+a[i][2];
            for(j=i+a[i][1] ; j<=n ; j++)
                if(mx[j]<d[i+a[i][1]-1])
                    mx[j] = d[i+a[i][1]-1];
        }
    for(i=1 ; i<=n ; i++)
        if(d[i]>mn)
            mn = d[i];
    printf("%d", mn);
}
