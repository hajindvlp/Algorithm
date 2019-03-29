#include <stdio.h>

int main()
{
    int n, a[101], i;
    int mn = 101, mx = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), mn = (mn>a[i])?a[i]:mn, mx = (mx<a[i])?a[i]:mx;

    printf("%d %d", mx, mn);
}
