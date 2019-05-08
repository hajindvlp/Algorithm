#include <stdio.h>
#include <algorithm>
#define INF 2000000000
#define MAX 1001
using namespace std;

int n, a[MAX], d[MAX], cnt, mx;

int main()
{
    int i, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        d[i] = INF;

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        k = lower_bound(d+1, d+cnt+1, a[i])-d;
        cnt++;
        if(k>mx)
            mx = k;
        d[k] = a[i];
    }
    printf("%d", n-mx);
}
