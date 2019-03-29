#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> a[100001];
int n;
long long int sum;

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

int main()
{
    int i;
    int x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &x, &y), a[i] = make_pair(y, x);
    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
    {
        if(a[i-1].first == a[i].first && a[i+1].first == a[i].first)
            sum+=(abs(a[i].second-a[i-1].second)>abs(a[i].second-a[i+1].second))?abs(a[i].second-a[i+1].second):abs(a[i].second-a[i-1].second);
        else if(a[i-1].first == a[i].first)
            sum+=abs(a[i].second-a[i-1].second);
        else if(a[i+1].first == a[i].first)
            sum+=abs(a[i].second-a[i+1].second);
    }
    printf("%lld", sum);
    return 0;
}
