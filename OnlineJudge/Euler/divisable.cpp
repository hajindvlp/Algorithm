#include <stdio.h>

int n, m, a[10001], d[10001], tmp[10001];

void pro()
{
    int i, j;

    for(i=0 ; i<=10000 ; i++)
        a[i] = d[i] = tmp[i] = 0;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]%m < 0)
            a[i] = m+a[i]%m;
        else
            a[i] = a[i]%m;
    }

    if(a[1]<0)
        tmp[a[1]%m+m] = 1;
    else
        tmp[a[1]%m] = 1;
    for(i=2 ; i<=n ; i++)
    {
        for(j=0 ; j<m ; j++)
            d[j] = tmp[j], tmp[j] = 0;
        for(j=0 ; j<m ; j++)
            if(d[j] == 1)
            {
                if((j-a[i])%m<0)
                    tmp[m+(j-a[i])%m] = 1;
                else
                    tmp[(j-a[i])%m] = 1;
                if((j+a[i])%m<0)
                    tmp[m+(j+a[i])%m] = 1;
                else
                    tmp[(j+a[i])%m] = 1;
            }
    }
    if(tmp[0] == 1)
        printf("Divisible\n");
    else
        printf("Not divisible\n");
}

int main ()
{
    int i;

    for(i=1 ; i<=3 ; i++)
        pro();
    return 0;
}
