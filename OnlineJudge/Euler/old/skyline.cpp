#include <stdio.h>

int a[101], n, mx, tmp;

int main()
{
    int x, y, z;
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        for(j=x ; j<y ; j++)
            if(a[j]<z)
                a[j] = z;
        if(y>mx)
            mx = y;
    }


    tmp = 0;
    for(i=1 ; i<=mx-1; i++)
        if(a[i]!=tmp)
        {
            tmp = a[i];
            printf("%d(%d)", i, tmp);
        }

    printf("%d", i);
    return 0;
}
