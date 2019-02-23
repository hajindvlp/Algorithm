#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int a[10001];
int lef, rig, best, mid;

bool isOk(int lim)
{
    int i, sum = 0;

    for(i=1 ; i<=n ; i++)
        sum+=min(a[i], lim);

    return (sum<=m) ?  true:false;
}

int main()
{
    int i, asum = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        asum+=a[i];
    }
    scanf("%d", &m);
    sort(a+1, a+n+1);
    lef = 0;
    rig = a[n];

    if(asum <= m)
        printf("%d", a[n]);
    else
    {
        while(lef<=rig)
        {
            mid = (lef+rig)/2;
            if(isOk(mid))
            {
                best = mid;
                lef = mid+1;
            }
            else
                rig = mid-1;
        }

        printf("%d", best);
    }
    return 0;
}
