#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int n;
pair<pair<int, int>, int> a[1001];

bool desc(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.first == b.first && a.second>b.second)
        return a<b;
    return a > b;
}

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &a[i].first.first, &a[i].first.second), a[i].second = i;

    sort(a+1, a+n+1, desc);
    for(i=1 ; i<=n ; i++)
        printf("%d %d %d\n", a[i].second, a[i].first.first, a[i].first.second);
    return 0;
}
