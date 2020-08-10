#include <algorithm>
#include <stdio.h>
#define MN 1005
using namespace std;

int n, a[MN], l[MN], r[MN];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; ++i)
    {
        l[i] = 1;
        for(int j = 0; j < i; ++j)
            if(a[j] < a[i])
                l[i] = max(l[i], l[j] + 1);
    }

    for(int i = n - 1; i >= 0; --i)
    {
        r[i] = 1;
        for(int j = n - 1; i < j; --j)
            if(a[j] < a[i])
                r[i] = max(r[i], r[j] + 1);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = max(ans, l[i] + r[i] - 1);

    printf("%d", ans);
}
