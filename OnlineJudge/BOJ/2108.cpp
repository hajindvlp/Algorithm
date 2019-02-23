#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[500001], sum, cnt[8001], mx, k;
int tmp;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        sum+=a[i];
        cnt[(8000+a[i])%8000]++;
    }
    sort(a+1, a+n+1);

    for(i=1 ; i<=8000 ; i++)
        if(cnt[i]>mx)
            mx = cnt[i], k = i;

    for(i=1 ; i<=8000 ; i++)
        if(mx == cnt[i])
            tmp++;

    printf("%.lf\n", (double)sum/n);
    printf("%d\n", a[n/2+1]);
    if(tmp>=2)
        printf("%d\n", a[2]);
    else
        printf("%d\n", k);
    printf("%d", a[n]-a[1]);
    return 0;
}
