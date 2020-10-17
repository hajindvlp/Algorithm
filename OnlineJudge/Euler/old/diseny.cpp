#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int , int> a[1001];

int n;

int main()
{
    int i;
    int s, e, mx = 1;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &a[i].first, &a[i].second);

    sort(a+1, a+n+1);
    for(i=1 ; i<=n-1 ; i++)
        if((a[i+1].first)-(a[i].second)>mx && a[i+1].first>a[i].second+1)
        {
            s = a[i].second+1;
            e = a[i+1].first-1;
            mx = (a[i+1].first)-(a[i].second);
        }
    if(mx == 0)
        printf("0");
    else
        printf("%d %d", s, e);

    return 0;
}
