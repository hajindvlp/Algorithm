#include <stdio.h>

int a[50001], check[50001], use[50001][3];
int e, n, cnt;
int d[50001];

int main()
{
    int i, j;
    int x, y, mx;

    scanf("%d", &e);
    while(1)
    {
        scanf("%d %d", &x, &y);
        n++;
        if(x == 0 && y == 0)
            break;
        if(x<0 && d[0]<y)
            d[0] = y, check[0] = n;
        if(x<y && d[x]<y)
            d[x] = y, check[x] = n;
        else if(d[y]<x)
            d[y] = x, check[y] = n;
    }

    for(i=0 ; i<e ; i)
    {
        mx = 0;
        for(j=i ; j<=d[i] ; j++)
            if(d[j]>mx)
                mx = d[j];

        use[++cnt][1] = i;
        use[cnt][2] = d[i];
        i = d[i];
        printf("%d ", i);
    }

    printf("%d\n", cnt);
    for(i=1 ; i<=cnt ; i++)
        printf("%d %d\n", use[i][1], use[i][2]);
    return 0;
}