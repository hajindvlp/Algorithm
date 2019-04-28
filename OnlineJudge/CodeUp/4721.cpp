#include <stdio.h>
#include <algorithm>
using namespace std;

pair<pair<int, pair<int, int>>, pair<int, int> > a[5];
int n;

int main()
{
    int i, j;
    int x;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=3 ; j++)
        {
            a[j].second.second = j;
            scanf("%d", &x);
            a[j].first.first+=x;
            if(x == 3) a[j].first.second.first++;
            else if(x == 2) a[j].first.second.second++;
            else a[j].second.first++;
        }}

    sort(a+1, a+3+1);

    if(a[3].first.first == a[3-1].first.first &&
       a[3].first.second == a[3-1].first.second &&
       a[3].second.first == a[3-1].second.first) printf("0 %d", a[3].first.first);
    else printf("%d %d", a[3].second.second, a[3].first.first);
}
