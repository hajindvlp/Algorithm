#include <stdio.h>

int a[4], n, b[51];
bool d[1000001] = {false}, dec;

int main()
{
    int i, j;

    a[1] = 1;
    scanf("%d %d %d", &a[2], &a[3], &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &b[i]);

    for(i=1 ; i<=1000000 ; i++)
    {
        for(j=1 ; j<=3 ; j++)
            if(i-a[j]>=0 && d[i-a[j]] == 0)
            {
                dec = false;
                break;
            }
        d[i] = !dec;
        dec = true;
    }
    for(i=1 ; i<=n ; i++)
    {
        if(d[b[i]])
            printf("A");
        else
            printf("B");
    }
    return 0;
}
