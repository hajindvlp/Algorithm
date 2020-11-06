#include <stdio.h>
#include <algorithm>
using namespace std;

int n, ans;
int a[500001];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
    {
        if(a[i]+i>n && ans<n-i+1)
            ans = n-i+1;
        else if(a[i]+i-1<=n && ans<a[i])
            ans = a[i];
    }
    printf("%d", ans);
    return 0;
}
