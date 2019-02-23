#include <stdio.h>
#include <algorithm>
using namespace std;

int n, mn = 1000000000, mx, tmp;
bool k;
pair<int, int> a[5001];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &a[i].first, &a[i].second);

    sort(a+1, a+n+1);
    for(i=1  ; i<=n-1 ; i++)
    {
        if(k && a[i].second<a[i+1].first && mx<a[i].second-tmp)
            mx = a[i].second-tmp, k = false;
        else if(!k && a[i].second>a[i+1].first)
            k = true, tmp = a[i].first;

        if(a[i].second<a[i+1].first && mn>a[i+1].first-a[i].second)
            mn = a[i+1].first-a[i].second;
    }
    printf("%d %d", mx, mn);
    return 0;
}
