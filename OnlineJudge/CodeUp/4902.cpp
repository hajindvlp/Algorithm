#include <stdio.h>

int n, a[30001], m, b[30001], s, e;
int sum[30001];
long long int asum;

int edge(int x)
{
    if(x>=m)
        return sum[m-1];
    else if(x<0)
        return 0;
    else
        return sum[x];
}

int main()
{
    int i;
    int x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &x, &y), a[x] = y;
    scanf("%d", &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), b[x] = y, sum[x] = sum[x-1]+y;
    scanf("%d %d", &s, &e);

    for(i=0 ; i<m ; i++)
        asum+=(edge(i+e)-edge(i+s-1))*a[i];
    printf("%d", asum);
}
