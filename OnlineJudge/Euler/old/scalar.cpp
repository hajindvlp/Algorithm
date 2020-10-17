#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
long long int a[805], b[805];
long long int ans = 0;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%lld", &a[i]);
    for(i=1 ; i<=n ; i++)
        scanf("%lld", &b[i]);

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    for(i=1 ; i<=n ; i++)
        ans += (a[n-i+1]*b[i]);

    printf("%lld", ans);
    return 0;
}
