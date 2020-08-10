#include <stdio.h>

int n, m;
long long int d[100001], sum[100001], mx;

int main()
{
    int i;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%lld", &d[i]), d[i]+=d[i-1];

    for(i=m ; i<=n ; i++)
        if(mx<d[i]-d[i-m])
            mx = d[i]-d[i-m];

    printf("%lld", mx);
    return 0;
}
