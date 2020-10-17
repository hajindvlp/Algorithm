#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[11];
long long int sum, tmp = 1;

int main()
{
    int i;
    int x, y;

    scanf("%d", &n);
    for(i=1 ;  i<=n ; i++)
        scanf("%d %d", &x, &y), a[i] = x+y;
    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
    {
        sum+=(long long int)(tmp*a[i]);
        tmp*=10;
    }

    printf("%lld", sum);
    return 0;
}
