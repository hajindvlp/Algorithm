#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> a[500001];
int n, m, cnt, sum, k;

int main()
{
    int i, x;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &x);
        if(x<0)
            a[i] = make_pair(abs(x), -1);
        else
            a[i] = make_pair(abs(x), 1);
    }

    sort(a+1, a+n+1);
    k = a[1].first;
    for(i=2 ; i<=n ; i++)
    {
        if(sum+k>m)
            break;
        cnt++;
        sum+=k;
        k = abs(a[i-1].first*a[i-1].second-a[i].first*a[i].second);
    }
    printf("%d", cnt);
    return 0;
}
