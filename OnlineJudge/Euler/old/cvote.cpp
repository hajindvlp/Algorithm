#include <stdio.h>
#include <algorithm>
using namespace std;

pair<pair<pair<int, int>, pair<int, int> >, int> a[4];
int n;

int main()
{
    int i, j, x;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=3 ; j++)
        {
            scanf("%d", &x);
            if(x == 3)
                a[j].first.first.first+=x, a[j].first.first.second++;
            else if(x == 2)
                a[j].first.first.first+=x, a[j].first.second.first++;
            else
                a[j].first.first.first+=x, a[j].first.second.second++;
            a[j].second = j;
        }

    sort(a+1, a+4);
    if(a[3-1].first.first.first == a[3].first.first.first && a[3-1].first.first.second == a[3].first.first.second && a[3-1].first.second.first == a[3].first.second.first&& a[3-1].first.second.second == a[3].first.second.second)
        printf("0 %d", a[3].first.first.first);
    else
        printf("%d %d", a[3].second, a[3].first.first.first);
    return 0;
}
