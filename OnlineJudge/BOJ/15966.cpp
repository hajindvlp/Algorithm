#include <stdio.h>
#include <algorithm>
using namespace std;

int n, ans, d[1000001];

int main()
{
    int i, x;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &x);
        d[x] = d[x-1]+1;
        ans = max(ans, d[x]);
    }
    printf("%d", ans);
    return 0;
}
