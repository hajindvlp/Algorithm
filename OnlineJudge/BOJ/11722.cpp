#include <stdio.h>
#include <algorithm>
#define INF 10000000
using namespace std;

int n, a[100001], d[100001], cnt, mx;

int main()
{
    int i, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        d[i] = INF;
    for(i=n ; i>=1 ; i--)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n ; i++)
    {
        k = lower_bound(d+1, d+cnt+1, a[i])-d;
        cnt++;
        if(k>mx)
            mx = k;
        d[k] = a[i];
    }
    printf("%d", mx);
}
