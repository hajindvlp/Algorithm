#include <stdio.h>

int n, mxsum, mnsum;
int a[101], b[101];

int mn(int x, int y)
{
    if(x>y)
        return y;
    return x;
}

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &b[i]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            mxsum+=mn(a[i], b[j]);

    for(i=1 ; i<=n ; i++)
    {
        bool k = false;
        for(j=1 ; j<=n ; j++)
            if(a[i] == b[j])
            {
                mnsum+=a[i];
                k = true;
            }
        if(!k)
            for(j=1 ; j<=n ; j++)
                if(a[i]<b[j])
                {
                    mnsum+=a[i];
                    break;
                }
    }

    printf("%d %d", mnsum, mxsum);
    return 0;
}
