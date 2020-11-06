#include <stdio.h>

int n, len, a[1000001];
int mn, mx;

int main()
{
    int i;

    scanf("%d %d", &len, &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        if(len-a[i]<a[i])
        {
            if(len-a[i]>mn)
                mn = len-a[i];
            if(a[i]>mx)
                mx = a[i];
        }
        else
        {
            if(len-a[i]>mx)
                mx = len-a[i];
            if(a[i]>mn)
                mn = a[i];
        }
    }

    printf("%d %d", mn, mx);
    return 0;
}
