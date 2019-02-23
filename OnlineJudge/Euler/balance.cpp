#include <stdio.h>

int a[31], w, n, m, mx;
bool check[15001], d[15001];

int abs(int x)
{
    if(x>0)
        return x;
    else
        return -x;
}

int main()
{
    int i, j;

    scanf("%d", &n);
    check[0] = d[0] = true;
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        for(j=0 ; j<=mx ; j++)
            if(check[j])
            {
                if(abs(a[i]-j)<=15000) d[abs(a[i]-j)] = true;
                if(a[i]+j <=15000) d[a[i]+j] = true;
                d[a[i]] = true;
            }
        mx += a[i];
        for(j=0 ; j<=mx ; j++)
            check[j] = d[j];
    }

    scanf("%d", &m);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d", &w);
        if(check[w])
            printf("Y ");
        else
            printf("N ");
    }
    return 0;
}
