#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[1000001], l, k, cnt;

int main()
{
    int i;

    scanf("%d %d %d", &n, &l, &k);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
        if(a[i]<=k)
        {
            cnt++;
            k+=l;
        }
    printf("%d", cnt);
    return 0;
}
