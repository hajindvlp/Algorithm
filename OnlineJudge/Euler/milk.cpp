#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> a[5001];
int n, m;
int sum;

int main()
{
    int i;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &a[i].first, &a[i].second);

    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
    {
        if(a[i].second<m)
        {
            sum+=a[i].first*a[i].second;
            m-=a[i].second;
        }
        else
        {
            sum+=a[i].first*m;
            break;
        }
    }
    printf("%d", sum);
    return 0;
}
