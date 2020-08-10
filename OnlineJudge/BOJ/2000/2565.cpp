#include <stdio.h>
#include <algorithm>
#define INF 2000000000
#define MAX 1001
using namespace std;

pair<int, int> p[MAX];
int n, a[MAX], d[MAX], cnt, mx;

int main()
{
    int i, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        d[i] = INF;
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &p[i].first, &p[i].second);
    sort(p+1, p+n+1);
    for(i=1 ; i<=n ; i++)
        a[i] = p[i].second;

    for(i=1 ; i<=n ; i++)
    {
        k = lower_bound(d+1, d+cnt+1, a[i])-d;
        cnt++;
        if(k>mx)
            mx = k;
        d[k] = a[i];
    }
    printf("%d", n-mx);
}
